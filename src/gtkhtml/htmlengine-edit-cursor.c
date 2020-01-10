/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*  This file is part of the GtkHTML library.
 *
 *  Copyright (C) 2000 Helix Code, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
*/

#include <config.h>
#include <gtk/gtk.h>
#include "gtkhtml.h"
#include "gtkhtml-private.h"
#include "htmlcursor.h"
#include "htmlengine.h"
#include "htmlengine-edit-cursor.h"
#include "htmlengine-edit-table.h"
#include "htmlengine-edit-tablecell.h"
#include "htmlgdkpainter.h"
#include "htmlimage.h"
#include "htmlobject.h"
#include "htmltable.h"
#include "htmlembedded.h"

static GdkColor table_stipple_active_on      = { 0, 0,      0,      0xffff };
static GdkColor table_stipple_active_off     = { 0, 0xffff, 0xffff, 0xffff };
static GdkColor table_stipple_non_active_on  = { 0, 0xaaaa, 0xaaaa, 0xaaaa };
static GdkColor table_stipple_non_active_off = { 0, 0xffff, 0xffff, 0xffff };

static GdkColor cell_stipple_active_on      = { 0, 0x7fff, 0x7fff, 0 };
static GdkColor cell_stipple_active_off     = { 0, 0xffff, 0xffff, 0xffff };
static GdkColor cell_stipple_non_active_on  = { 0, 0x7aaa, 0x7aaa, 0x7aaa };
static GdkColor cell_stipple_non_active_off = { 0, 0xffff, 0xffff, 0xffff };

static GdkColor image_stipple_active_on      = { 0, 0xffff, 0,      0 };
static GdkColor image_stipple_active_off     = { 0, 0xffff, 0xffff, 0xffff };

static gint blink_timeout = 500;

void
html_engine_set_cursor_blink_timeout (gint timeout)
{
	blink_timeout = timeout;
}

void
html_engine_hide_cursor (HTMLEngine *engine)
{
	HTMLEngine *e = engine;

	g_return_if_fail (engine != NULL);
	g_return_if_fail (HTML_IS_ENGINE (engine));

	if ((engine->editable || engine->caret_mode) && engine->cursor_hide_count == 0) {
		if (!engine->editable) {
			e = html_object_engine (engine->cursor->object, NULL);
			if (e) {
				e->caret_mode = engine->caret_mode;
				html_cursor_copy (e->cursor, engine->cursor);
			} else	e = engine;
		}
		html_engine_draw_cursor_in_area (e, 0, 0, -1, -1);
	}

	engine->cursor_hide_count++;
}

void
html_engine_show_cursor (HTMLEngine *engine)
{
	HTMLEngine * e = engine;

	g_return_if_fail (engine != NULL);
	g_return_if_fail (HTML_IS_ENGINE (engine));
	g_return_if_fail (engine->cursor != NULL);

	if (engine->cursor_hide_count > 0) {
		engine->cursor_hide_count--;
		if ((engine->editable || engine->caret_mode) && engine->cursor_hide_count == 0) {
			if (!engine->editable) {
				e = html_object_engine (engine->cursor->object, NULL);
				if (e) {
					e->caret_mode = engine->caret_mode;
					html_cursor_copy (e->cursor, engine->cursor);
				} else e = engine;
			}
			html_engine_draw_cursor_in_area (e, 0, 0, -1, -1);
		}
	}
}

static gboolean
clip_cursor (HTMLEngine *engine,
             gint x,
             gint y,
             gint width,
             gint height,
             gint *x1,
             gint *y1,
             gint *x2,
             gint *y2)
{
	if (*x1 > x + width || *y1 > y + height || *x2 < x || *y2 < y)
		return FALSE;

	*x1 = CLAMP (*x1, x, x + width);
	*x2 = CLAMP (*x2, x, x + width);
	*y1 = CLAMP (*y1, y, y + height);
	*y2 = CLAMP (*y2, y, y + height);

	return TRUE;
}

static void
draw_cursor_rectangle (HTMLEngine *e,
                       gint x1,
                       gint y1,
                       gint x2,
                       gint y2,
                       GdkColor *on_color,
                       GdkColor *off_color,
                       gint offset)
{
	cairo_t *cr;
	const double dashes[2] = { 1, 3 };
	gint ndash = G_N_ELEMENTS (dashes);

	if (x1 > x2 || y1 > y2 || !e->window)
		return;

	/* FIXME: what is the off color for? */
	cr = gdk_cairo_create (e->window);
	gdk_cairo_set_source_color (cr, on_color);
	cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
	cairo_set_dash (cr, dashes, ndash, offset);
	cairo_rectangle (cr, x1 - 0.5, y1 - 0.5, x2 - x1 + 1, y2 - y1 + 1);
	cairo_set_line_width (cr, 1.0);
	cairo_stroke (cr);
	cairo_destroy (cr);
}

static gint cursor_enabled = TRUE;

static inline void
refresh_under_cursor (HTMLEngine *e,
                      HTMLCursorRectangle *cr,
                      gboolean *enabled)
{
	if (cr->x1 > cr->x2 || cr->y1 > cr->y2)
		return;

	*enabled = cursor_enabled = FALSE;
	html_engine_draw (e, cr->x1, cr->y1,
			  cr->x2 - cr->x1 + 1, cr->y2 - cr->y1 + 1);
	*enabled = cursor_enabled = TRUE;
}

#define COLORS(x) animate ? &x ## _stipple_active_on  : &x ## _stipple_non_active_on, \
                  animate ? &x ## _stipple_active_off : &x ## _stipple_non_active_off

static void
html_engine_draw_image_cursor (HTMLEngine *e)
{
	HTMLCursorRectangle *cr;
	HTMLObject *io;
	static gboolean enabled = TRUE;

	if (!enabled)
		return;

	cr    = &e->cursor_image;
	io    = e->cursor->object;

	if (io && HTML_IS_IMAGE (e->cursor->object)) {
		static gint offset = 3;

		if (io != cr->object) {
			if (cr->object)
				refresh_under_cursor (e, cr, &enabled);
			cr->object = io;
		}

		html_object_calc_abs_position (io, &cr->x1, &cr->y1);
		cr->x2 = cr->x1 + io->width - 1;
		cr->y2 = cr->y1 + io->descent - 1;
		cr->y1 -= io->ascent;

		draw_cursor_rectangle (e, cr->x1, cr->y1, cr->x2, cr->y2,
				       &image_stipple_active_on, &image_stipple_active_off, offset);
		if (!offset)
			offset = 3;
		else
			offset--;
	} else
		if (cr->object) {
			refresh_under_cursor (e, cr, &enabled);
			cr->object = NULL;
		}
}

void
html_engine_draw_cell_cursor (HTMLEngine *e)
{
	HTMLCursorRectangle *cr;
	HTMLTableCell *cell;
	HTMLObject    *co;
	static gboolean enabled = TRUE;

	if (!enabled)
		return;

	cr   = &e->cursor_cell;
	cell = html_engine_get_table_cell (e);
	co   = HTML_OBJECT (cell);

	if (cell) {
		static gint offset = 0;
		gboolean animate;

		if (co != cr->object) {
			if (cr->object)
				refresh_under_cursor (e, cr, &enabled);
			cr->object = co;
		}

		html_object_calc_abs_position (co, &cr->x1, &cr->y2);
		cr->x2  = cr->x1 + co->width - 1;
		cr->y2 -= 2;
		cr->y1  = cr->y2 - (co->ascent + co->descent - 2);

		animate = !HTML_IS_IMAGE (e->cursor->object);
		if (animate) {
			offset++;
			offset %= 4;
		}
		draw_cursor_rectangle (e, cr->x1, cr->y1, cr->x2, cr->y2, COLORS (cell), offset);
	} else
		if (cr->object) {
			refresh_under_cursor (e, cr, &enabled);
			cr->object = NULL;
		}
}

void
html_engine_draw_table_cursor (HTMLEngine *e)
{
	HTMLCursorRectangle *cr;
	HTMLTable *table;
	HTMLObject *to;
	static gboolean enabled = TRUE;

	if (!enabled)
		return;

	cr    = &e->cursor_table;
	table = html_engine_get_table (e);
	to    = HTML_OBJECT (table);

	if (table) {
		static gint offset = 0;
		gboolean animate;

		if (to != cr->object) {
			if (cr->object)
				refresh_under_cursor (e, cr, &enabled);
			cr->object = to;
		}

		html_object_calc_abs_position (to, &cr->x1, &cr->y2);
		cr->x2 = cr->x1 + to->width - 1;
		cr->y2--;
		cr->y1 = cr->y2 - (to->ascent + to->descent - 1);

		animate = HTML_IS_TABLE (e->cursor->object) && !html_engine_get_table_cell (e);
		if (animate) {
			offset++;
			offset %= 4;
		}
		draw_cursor_rectangle (e, cr->x1, cr->y1, cr->x2, cr->y2, COLORS (table), offset);
	} else
		if (cr->object) {
			refresh_under_cursor (e, cr, &enabled);
			cr->object = NULL;
		}
}

void
html_engine_draw_cursor_in_area (HTMLEngine *engine,
                                 gint x,
                                 gint y,
                                 gint width,
                                 gint height)
{
	HTMLObject *obj;
	guint offset;
	gint x1, y1, x2, y2, sc_x, sc_y;
	GdkRectangle pos;
	GtkAdjustment *hadj, *vadj;

	if ((engine->editable || engine->caret_mode) && (engine->cursor_hide_count <= 0 && !engine->thaw_idle_id)) {
		html_engine_draw_table_cursor (engine);
		html_engine_draw_cell_cursor (engine);
		html_engine_draw_image_cursor (engine);
	}

	if (!cursor_enabled || engine->cursor_hide_count > 0 || !(engine->editable || engine->caret_mode) || engine->thaw_idle_id)
		return;

	obj = engine->cursor->object;
	if (obj == NULL || engine->window == NULL)
		return;

	offset = engine->cursor->offset;

	if (width < 0 || height < 0) {
		width = html_engine_get_doc_width (engine);
		height = html_engine_get_doc_height (engine);
		x = 0;
		y = 0;
	}

	html_object_get_cursor (obj, engine->painter, offset, &x1, &y1, &x2, &y2);
	while (obj) {
		if (html_object_is_frame (obj)) {
			x1 -= HTML_EMBEDDED (obj)->abs_x;
			x2 -= HTML_EMBEDDED (obj)->abs_x;
			y1 -= HTML_EMBEDDED (obj)->abs_y;
			y2 -= HTML_EMBEDDED (obj)->abs_y;
			break;
		}
		obj = obj->parent;
	}

	/* get scroll offset */
	hadj = gtk_layout_get_hadjustment (GTK_LAYOUT (engine->widget));
	vadj = gtk_layout_get_vadjustment (GTK_LAYOUT (engine->widget));
	sc_x = (gint) gtk_adjustment_get_value (hadj);
	sc_y = (gint) gtk_adjustment_get_value (vadj);

	pos.x = x1 - sc_x;
	pos.y = y1 - sc_y;
	pos.width = x2 - x1;
	pos.height = y2 - y1;

	gtk_im_context_set_cursor_location (GTK_HTML (engine->widget)->priv->im_context, &pos);

	if (clip_cursor (engine, x, y, width, height, &x1, &y1, &x2, &y2)) {
		cairo_t *cr;
		gboolean using_painter_cr;

		using_painter_cr = engine->painter &&
		    HTML_IS_GDK_PAINTER (engine->painter) &&
		    HTML_GDK_PAINTER (engine->painter)->cr != NULL;

		if (using_painter_cr) {
			HTMLGdkPainter *gdk_painter = HTML_GDK_PAINTER (engine->painter);

			cr = gdk_painter->cr;
			cairo_save (cr);

			x1 -= gdk_painter->x1;
			y1 -= gdk_painter->y1;
			x2 -= gdk_painter->x1;
			y2 -= gdk_painter->y1;
		} else {
			cr = gdk_cairo_create (engine->window);
		}

		cairo_set_source_rgb (cr, 1, 1, 1);
		cairo_set_operator (cr, CAIRO_OPERATOR_DIFFERENCE);
		cairo_set_line_cap (cr, CAIRO_LINE_CAP_SQUARE);
		cairo_move_to (cr, x1 + 0.5, y1 + 0.5);
		cairo_line_to (cr, x2 + 0.5, y2 - 0.5);
		cairo_set_line_width (cr, 1);
		cairo_stroke (cr);

		if (using_painter_cr)
			cairo_restore (cr);
		else
			cairo_destroy (cr);
	}
}


/* Blinking cursor implementation.  */

static gint
blink_timeout_cb (gpointer data)
{
	HTMLEngine *engine;

	g_return_val_if_fail (HTML_IS_ENGINE (data), FALSE);
	engine = HTML_ENGINE (data);

	engine->blinking_status = !engine->blinking_status;

	if (engine->blinking_status)
		html_engine_show_cursor (engine);
	else
		html_engine_hide_cursor (engine);

	return TRUE;
}

void
html_engine_setup_blinking_cursor (HTMLEngine *engine)
{
	g_return_if_fail (engine != NULL);
	g_return_if_fail (HTML_IS_ENGINE (engine));
	g_return_if_fail (engine->blinking_timer_id == 0);

	html_engine_show_cursor (engine);
	engine->blinking_status = FALSE;

	blink_timeout_cb (engine);
	if (blink_timeout > 0)
		engine->blinking_timer_id = g_timeout_add (blink_timeout, blink_timeout_cb, engine);
	else
		engine->blinking_timer_id = -1;
}

void
html_engine_stop_blinking_cursor (HTMLEngine *engine)
{
	g_return_if_fail (engine != NULL);
	g_return_if_fail (HTML_IS_ENGINE (engine));
	g_return_if_fail (engine->blinking_timer_id != 0);

	if (engine->blinking_status) {
		html_engine_hide_cursor (engine);
		engine->blinking_status = FALSE;
	}

	if (engine->blinking_timer_id != -1)
		g_source_remove (engine->blinking_timer_id);
	engine->blinking_timer_id = 0;
}

void
html_engine_reset_blinking_cursor (HTMLEngine *engine)
{
	g_return_if_fail (engine != NULL);
	g_return_if_fail (HTML_IS_ENGINE (engine));
	g_return_if_fail (engine->blinking_timer_id != 0);

	if (engine->blinking_status)
		return;

	html_engine_show_cursor (engine);
	engine->blinking_status = TRUE;

	if (engine->blinking_timer_id != -1)
		g_source_remove (engine->blinking_timer_id);

	if (blink_timeout > 0)
		engine->blinking_timer_id = g_timeout_add (blink_timeout, blink_timeout_cb, engine);
	else {
		engine->blinking_timer_id = -1;
		/* show the cursor */
		engine->blinking_status = FALSE;
		blink_timeout_cb (engine);
	}
}
