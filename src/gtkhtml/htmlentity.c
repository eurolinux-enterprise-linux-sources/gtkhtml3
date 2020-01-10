/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf --struct-type -l -N html_entity_hash -L ANSI-C htmlentity.gperf  */
/* Computed positions: -k'1-3,5,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "htmlentity.gperf"

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* htmlentity.c
 *
 * This file is part of the GtkHTML library.
 *
 * Copyright (C) 1999  Helix Code, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Author: Ettore Perazzoli
 */

#include <config.h>
#include <string.h>
#include <stdlib.h>
#include "gtkhtml-compat.h"

#include <glib.h>
#include "htmlentity.h"

#line 35 "htmlentity.gperf"
struct _EntityEntry {
	const gchar *name;
	gulong value;
};

#define TOTAL_KEYWORDS 253
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 8
#define MAX_HASH_VALUE 738
/* maximum key range = 731, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static guint
hash (register const gchar *str,
      register guint len)
{
  static gushort asso_values[] =
    {
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739,  10,
       35,  20,   0, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 175, 135,  30,  60,  95,
	5,   0,   5, 180, 739,  15,   5,   0,  15, 110,
      110, 739,   5,   5,   5, 100, 739, 739,   0,  20,
	0, 739, 739, 739, 739, 739, 739,   5,  60,  50,
	0,  15, 144, 115, 215,  10, 225,  10,  95, 125,
       25,   0,   5, 218,  90,  20,   0,  65,  35,  55,
       45, 115,   5,  15, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739
    };
  register gint hval = len;

  switch (hval)
    {
      default:
	hval += asso_values[(guchar) str[4]];
      /*FALLTHROUGH*/
      case 4:
      case 3:
	hval += asso_values[(guchar) str[2]];
      /*FALLTHROUGH*/
      case 2:
	hval += asso_values[(guchar) str[1]+1];
      /*FALLTHROUGH*/
      case 1:
	hval += asso_values[(guchar) str[0]];
	break;
    }
  return hval + asso_values[(guchar) str[len - 1]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
static struct _EntityEntry *
html_entity_hash (register const gchar *str,
                  register guint len)
{
  static guchar lengthtable[] =
    {
       0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  3,
       0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  4,  0,  0,  0,
       3,  4,  0,  0,  0,  3,  4,  0,  0,  0,  3,  4,  5,  6,
       0,  3,  4,  5,  6,  0,  0,  4,  0,  6,  0,  0,  0,  5,
       6,  0,  0,  0,  5,  0,  0,  3,  0,  5,  0,  0,  3,  4,
       5,  0,  0,  0,  4,  5,  0,  0,  0,  4,  5,  0,  0,  3,
       4,  5,  0,  0,  0,  0,  5,  0,  0,  3,  0,  5,  6,  0,
       3,  4,  0,  6,  2,  3,  4,  5,  0,  0,  0,  0,  0,  6,
       2,  3,  0,  5,  6,  2,  0,  0,  5,  6,  0,  3,  0,  5,
       0,  2,  0,  0,  5,  6,  0,  3,  4,  5,  6,  0,  0,  0,
       0,  6,  0,  3,  4,  5,  6,  0,  0,  4,  5,  6,  0,  4,
       4,  0,  6,  7,  4,  4,  5,  0,  2,  8,  4,  5,  6,  0,
       4,  0,  5,  6,  0,  3,  0,  5,  6,  0,  3,  4,  5,  6,
       2,  0,  0,  6,  2,  0,  0,  0,  0,  6,  0,  3,  4,  6,
       6,  0,  3,  4,  5,  6,  0,  0,  0,  0,  6,  0,  3,  5,
       5,  0,  0,  4,  0,  5,  6,  0,  4,  0,  6,  6,  0,  4,
       0,  5,  6,  2,  0,  0,  0,  6,  0,  0,  0,  0,  0,  2,
       3,  0,  0,  6,  2,  0,  4,  5,  6,  4,  4,  0,  0,  0,
       0,  0,  5,  5,  2,  4,  0,  4,  5,  0,  2,  3,  4,  0,
       0,  7,  0,  4,  5,  6,  0,  0,  4,  5,  2,  0,  0,  4,
       5,  6,  2,  3,  6,  5,  6,  0,  4,  4,  5,  6,  4,  5,
       4,  5,  0,  7,  5,  4,  5,  0,  0,  3,  4,  5,  6,  0,
       3,  4,  6,  6,  3,  5,  5,  5,  0,  0,  5,  4,  5,  0,
       0,  0,  4,  0,  0,  0,  5,  4,  5,  0,  0,  5,  4,  0,
       6,  0,  4,  4,  0,  0,  0,  0,  0,  0,  6,  2,  0,  0,
       6,  6,  0,  0,  4,  5,  6,  0,  5,  4,  5,  6,  0,  0,
       5,  5,  6,  0,  3,  4,  0,  6,  0,  5,  4,  5,  6,  3,
       5,  0,  7,  0,  0,  0,  4,  0,  0,  0,  0,  5,  6,  0,
       0,  0,  5,  5,  6,  0,  0,  0,  0,  6,  0,  0,  0,  5,
       0,  0,  0,  4,  0,  0,  0,  0,  4,  0,  0,  0,  0,  4,
       5,  0,  0,  0,  0,  0,  6,  0,  0,  0,  7,  0,  0,  0,
       4,  6,  0,  0,  0,  4,  5,  0,  0,  0,  0,  5,  6,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  4,  7,  6,
       0,  0,  0,  7,  0,  3,  3,  0,  0,  6,  0,  0,  5,  6,
       0,  0,  0,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  3,
       0,  0,  0,  0,  0,  0,  5,  0,  0,  3,  0,  6,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  4,  0,  6,  0,  0,  0,  0,  6,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  5,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5
    };
  static struct _EntityEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 53 "htmlentity.gperf"
      {"and", 8743},
      {""}, {""}, {""}, {""},
#line 134 "htmlentity.gperf"
      {"int", 8747},
      {""}, {""}, {""}, {""},
#line 230 "htmlentity.gperf"
      {"Rho", 929},
      {""}, {""}, {""}, {""}, {""},
#line 136 "htmlentity.gperf"
      {"iota", 953},
      {""}, {""}, {""},
#line 218 "htmlentity.gperf"
      {"psi", 968},
#line 215 "htmlentity.gperf"
      {"prod", 8719},
      {""}, {""}, {""},
#line 171 "htmlentity.gperf"
      {"not", 172},
#line 216 "htmlentity.gperf"
      {"prop", 8733},
      {""}, {""}, {""},
#line 207 "htmlentity.gperf"
      {"phi", 966},
#line 238 "htmlentity.gperf"
      {"sdot", 8901},
#line 259 "htmlentity.gperf"
      {"theta", 952},
#line 236 "htmlentity.gperf"
      {"Scaron", 352},
      {""},
#line 52 "htmlentity.gperf"
      {"amp", 38},
#line 99 "htmlentity.gperf"
      {"ensp", 8194},
#line 258 "htmlentity.gperf"
      {"Theta", 920},
#line 257 "htmlentity.gperf"
      {"there4", 8756},
      {""}, {""},
#line 138 "htmlentity.gperf"
      {"isin", 8712},
      {""},
#line 261 "htmlentity.gperf"
      {"thinsp", 8201},
      {""}, {""}, {""},
#line 188 "htmlentity.gperf"
      {"omega", 969},
#line 237 "htmlentity.gperf"
      {"scaron", 353},
      {""}, {""}, {""},
#line 266 "htmlentity.gperf"
      {"trade", 8482},
      {""}, {""},
#line 73 "htmlentity.gperf"
      {"Chi", 935},
      {""},
#line 263 "htmlentity.gperf"
      {"thorn", 254},
      {""}, {""},
#line 252 "htmlentity.gperf"
      {"sup", 8835},
#line 98 "htmlentity.gperf"
      {"emsp", 8195},
#line 213 "htmlentity.gperf"
      {"prime", 8242},
      {""}, {""}, {""},
#line 249 "htmlentity.gperf"
      {"sup1", 185},
#line 132 "htmlentity.gperf"
      {"image", 8465},
      {""}, {""}, {""},
#line 253 "htmlentity.gperf"
      {"supe", 8839},
#line 212 "htmlentity.gperf"
      {"pound", 163},
      {""}, {""},
#line 74 "htmlentity.gperf"
      {"chi", 967},
#line 251 "htmlentity.gperf"
      {"sup3", 179},
#line 172 "htmlentity.gperf"
      {"notin", 8713},
      {""}, {""}, {""}, {""},
#line 142 "htmlentity.gperf"
      {"kappa", 954},
      {""}, {""},
#line 104 "htmlentity.gperf"
      {"eta", 951},
      {""},
#line 141 "htmlentity.gperf"
      {"Kappa", 922},
#line 198 "htmlentity.gperf"
      {"otilde", 245},
      {""},
#line 80 "htmlentity.gperf"
      {"cup", 8746},
#line 250 "htmlentity.gperf"
      {"sup2", 178},
      {""},
#line 60 "htmlentity.gperf"
      {"atilde", 227},
#line 164 "htmlentity.gperf"
      {"Mu", 924},
#line 231 "htmlentity.gperf"
      {"rho", 961},
#line 167 "htmlentity.gperf"
      {"nbsp", 160},
#line 44 "htmlentity.gperf"
      {"acute", 180},
      {""}, {""}, {""}, {""}, {""},
#line 174 "htmlentity.gperf"
      {"Ntilde", 209},
#line 192 "htmlentity.gperf"
      {"or", 8744},
#line 154 "htmlentity.gperf"
      {"loz", 9674},
      {""},
#line 181 "htmlentity.gperf"
      {"ocirc", 244},
#line 199 "htmlentity.gperf"
      {"otimes", 8855},
#line 176 "htmlentity.gperf"
      {"Nu", 925},
      {""}, {""},
#line 43 "htmlentity.gperf"
      {"acirc", 226},
#line 175 "htmlentity.gperf"
      {"ntilde", 241},
      {""},
#line 68 "htmlentity.gperf"
      {"cap", 8745},
      {""},
#line 128 "htmlentity.gperf"
      {"icirc", 238},
      {""},
#line 177 "htmlentity.gperf"
      {"nu", 957},
      {""}, {""},
#line 94 "htmlentity.gperf"
      {"ecirc", 234},
#line 179 "htmlentity.gperf"
      {"oacute", 243},
      {""},
#line 217 "htmlentity.gperf"
      {"Psi", 936},
#line 247 "htmlentity.gperf"
      {"sube", 8838},
#line 58 "htmlentity.gperf"
      {"asymp", 8776},
#line 41 "htmlentity.gperf"
      {"aacute", 225},
      {""}, {""}, {""}, {""},
#line 126 "htmlentity.gperf"
      {"iacute", 237},
      {""},
#line 206 "htmlentity.gperf"
      {"Phi", 934},
#line 109 "htmlentity.gperf"
      {"euro", 8364},
#line 110 "htmlentity.gperf"
      {"exist", 8707},
#line 92 "htmlentity.gperf"
      {"eacute", 233},
      {""}, {""},
#line 194 "htmlentity.gperf"
      {"ordm", 186},
#line 51 "htmlentity.gperf"
      {"alpha", 945},
#line 284 "htmlentity.gperf"
      {"Yacute", 221},
      {""},
#line 289 "htmlentity.gperf"
      {"Zeta", 918},
#line 173 "htmlentity.gperf"
      {"nsub", 8836},
      {""},
#line 69 "htmlentity.gperf"
      {"Ccedil", 199},
#line 190 "htmlentity.gperf"
      {"omicron", 959},
#line 290 "htmlentity.gperf"
      {"zeta", 950},
#line 203 "htmlentity.gperf"
      {"part", 8706},
#line 166 "htmlentity.gperf"
      {"nabla", 8711},
      {""},
#line 158 "htmlentity.gperf"
      {"lt", 60},
#line 260 "htmlentity.gperf"
      {"thetasym", 977},
#line 202 "htmlentity.gperf"
      {"para", 182},
#line 187 "htmlentity.gperf"
      {"Omega", 937},
#line 233 "htmlentity.gperf"
      {"rsaquo", 8250},
      {""},
#line 193 "htmlentity.gperf"
      {"ordf", 170},
      {""},
#line 186 "htmlentity.gperf"
      {"oline", 8254},
#line 156 "htmlentity.gperf"
      {"lsaquo", 8249},
      {""},
#line 103 "htmlentity.gperf"
      {"Eta", 919},
      {""},
#line 214 "htmlentity.gperf"
      {"Prime", 8243},
#line 70 "htmlentity.gperf"
      {"ccedil", 231},
      {""},
#line 246 "htmlentity.gperf"
      {"sub", 8834},
#line 78 "htmlentity.gperf"
      {"copy", 169},
#line 272 "htmlentity.gperf"
      {"ucirc", 251},
#line 153 "htmlentity.gperf"
      {"lowast", 8727},
#line 120 "htmlentity.gperf"
      {"gt", 62},
      {""}, {""},
#line 114 "htmlentity.gperf"
      {"frac14", 188},
#line 169 "htmlentity.gperf"
      {"ne", 8800},
      {""}, {""}, {""}, {""},
#line 137 "htmlentity.gperf"
      {"iquest", 191},
      {""},
#line 256 "htmlentity.gperf"
      {"tau", 964},
#line 135 "htmlentity.gperf"
      {"Iota", 921},
#line 115 "htmlentity.gperf"
      {"frac34", 190},
#line 268 "htmlentity.gperf"
      {"uacute", 250},
      {""},
#line 255 "htmlentity.gperf"
      {"Tau", 932},
#line 77 "htmlentity.gperf"
      {"cong", 8773},
#line 117 "htmlentity.gperf"
      {"Gamma", 915},
#line 143 "htmlentity.gperf"
      {"Lambda", 923},
      {""}, {""}, {""}, {""},
#line 197 "htmlentity.gperf"
      {"Otilde", 213},
      {""},
#line 105 "htmlentity.gperf"
      {"ETH", 208},
#line 133 "htmlentity.gperf"
      {"infin", 8734},
#line 93 "htmlentity.gperf"
      {"Ecirc", 202},
      {""}, {""},
#line 65 "htmlentity.gperf"
      {"beta", 946},
      {""},
#line 271 "htmlentity.gperf"
      {"Ucirc", 219},
#line 66 "htmlentity.gperf"
      {"brvbar", 166},
      {""},
#line 239 "htmlentity.gperf"
      {"sect", 167},
      {""},
#line 113 "htmlentity.gperf"
      {"frac12", 189},
#line 81 "htmlentity.gperf"
      {"curren", 164},
      {""},
#line 72 "htmlentity.gperf"
      {"cent", 162},
      {""},
#line 180 "htmlentity.gperf"
      {"Ocirc", 212},
#line 91 "htmlentity.gperf"
      {"Eacute", 201},
#line 165 "htmlentity.gperf"
      {"mu", 956},
      {""}, {""}, {""},
#line 267 "htmlentity.gperf"
      {"Uacute", 218},
      {""}, {""}, {""}, {""}, {""},
#line 282 "htmlentity.gperf"
      {"Xi", 926},
#line 54 "htmlentity.gperf"
      {"ang", 8736},
      {""}, {""},
#line 178 "htmlentity.gperf"
      {"Oacute", 211},
#line 209 "htmlentity.gperf"
      {"pi", 960},
      {""},
#line 84 "htmlentity.gperf"
      {"darr", 8595},
#line 102 "htmlentity.gperf"
      {"equiv", 8801},
#line 285 "htmlentity.gperf"
      {"yacute", 253},
#line 55 "htmlentity.gperf"
      {"apos", 39},
#line 205 "htmlentity.gperf"
      {"perp", 8869},
      {""}, {""}, {""}, {""}, {""},
#line 88 "htmlentity.gperf"
      {"delta", 948},
#line 220 "htmlentity.gperf"
      {"radic", 8730},
#line 151 "htmlentity.gperf"
      {"le", 8804},
#line 219 "htmlentity.gperf"
      {"quot", 34},
      {""},
#line 201 "htmlentity.gperf"
      {"ouml", 246},
#line 79 "htmlentity.gperf"
      {"crarr", 8629},
      {""},
#line 170 "htmlentity.gperf"
      {"ni", 8715},
#line 240 "htmlentity.gperf"
      {"shy", 173},
#line 62 "htmlentity.gperf"
      {"auml", 228},
      {""}, {""},
#line 189 "htmlentity.gperf"
      {"Omicron", 927},
      {""},
#line 140 "htmlentity.gperf"
      {"iuml", 239},
#line 57 "htmlentity.gperf"
      {"aring", 229},
#line 59 "htmlentity.gperf"
      {"Atilde", 195},
      {""}, {""},
#line 108 "htmlentity.gperf"
      {"euml", 235},
#line 89 "htmlentity.gperf"
      {"diams", 9830},
#line 119 "htmlentity.gperf"
      {"ge", 8805},
      {""}, {""},
#line 288 "htmlentity.gperf"
      {"Yuml", 376},
#line 97 "htmlentity.gperf"
      {"empty", 8709},
#line 90 "htmlentity.gperf"
      {"divide", 247},
#line 283 "htmlentity.gperf"
      {"xi", 958},
#line 275 "htmlentity.gperf"
      {"uml", 168},
#line 245 "htmlentity.gperf"
      {"spades", 9824},
#line 76 "htmlentity.gperf"
      {"clubs", 9827},
#line 82 "htmlentity.gperf"
      {"dagger", 8224},
      {""},
#line 64 "htmlentity.gperf"
      {"Beta", 914},
#line 67 "htmlentity.gperf"
      {"bull", 8226},
#line 42 "htmlentity.gperf"
      {"Acirc", 194},
#line 144 "htmlentity.gperf"
      {"lambda", 955},
#line 111 "htmlentity.gperf"
      {"fnof", 402},
#line 235 "htmlentity.gperf"
      {"sbquo", 8218},
#line 221 "htmlentity.gperf"
      {"rang", 9002},
#line 127 "htmlentity.gperf"
      {"Icirc", 206},
      {""},
#line 49 "htmlentity.gperf"
      {"alefsym", 8501},
#line 63 "htmlentity.gperf"
      {"bdquo", 8222},
#line 145 "htmlentity.gperf"
      {"lang", 9001},
#line 225 "htmlentity.gperf"
      {"rceil", 8969},
      {""}, {""},
#line 210 "htmlentity.gperf"
      {"piv", 982},
#line 292 "htmlentity.gperf"
      {"zwnj", 8204},
#line 149 "htmlentity.gperf"
      {"lceil", 8968},
#line 40 "htmlentity.gperf"
      {"Aacute", 193},
      {""},
#line 248 "htmlentity.gperf"
      {"sum", 8721},
#line 269 "htmlentity.gperf"
      {"uarr", 8593},
#line 281 "htmlentity.gperf"
      {"weierp", 8472},
#line 125 "htmlentity.gperf"
      {"Iacute", 205},
#line 286 "htmlentity.gperf"
      {"yen", 165},
#line 234 "htmlentity.gperf"
      {"rsquo", 8217},
#line 87 "htmlentity.gperf"
      {"Delta", 916},
#line 118 "htmlentity.gperf"
      {"gamma", 947},
      {""}, {""},
#line 157 "htmlentity.gperf"
      {"lsquo", 8216},
#line 85 "htmlentity.gperf"
      {"dArr", 8659},
#line 50 "htmlentity.gperf"
      {"Alpha", 913},
      {""}, {""}, {""},
#line 280 "htmlentity.gperf"
      {"uuml", 252},
      {""}, {""}, {""},
#line 226 "htmlentity.gperf"
      {"rdquo", 8221},
#line 159 "htmlentity.gperf"
      {"macr", 175},
#line 262 "htmlentity.gperf"
      {"THORN", 222},
      {""}, {""},
#line 150 "htmlentity.gperf"
      {"ldquo", 8220},
#line 223 "htmlentity.gperf"
      {"rarr", 8594},
      {""},
#line 196 "htmlentity.gperf"
      {"oslash", 248},
      {""},
#line 227 "htmlentity.gperf"
      {"real", 8476},
#line 147 "htmlentity.gperf"
      {"larr", 8592},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 83 "htmlentity.gperf"
      {"Dagger", 8225},
#line 208 "htmlentity.gperf"
      {"Pi", 928},
      {""}, {""},
#line 204 "htmlentity.gperf"
      {"permil", 8240},
#line 211 "htmlentity.gperf"
      {"plusmn", 177},
      {""}, {""},
#line 107 "htmlentity.gperf"
      {"Euml", 203},
#line 264 "htmlentity.gperf"
      {"tilde", 732},
#line 162 "htmlentity.gperf"
      {"middot", 183},
      {""},
#line 191 "htmlentity.gperf"
      {"oplus", 8853},
#line 279 "htmlentity.gperf"
      {"Uuml", 220},
#line 241 "htmlentity.gperf"
      {"Sigma", 931},
#line 185 "htmlentity.gperf"
      {"ograve", 242},
      {""}, {""},
#line 116 "htmlentity.gperf"
      {"frasl", 8260},
#line 254 "htmlentity.gperf"
      {"szlig", 223},
#line 48 "htmlentity.gperf"
      {"agrave", 224},
      {""},
#line 155 "htmlentity.gperf"
      {"lrm", 8206},
#line 200 "htmlentity.gperf"
      {"Ouml", 214},
      {""},
#line 131 "htmlentity.gperf"
      {"igrave", 236},
      {""},
#line 222 "htmlentity.gperf"
      {"raquo", 187},
#line 287 "htmlentity.gperf"
      {"yuml", 255},
#line 242 "htmlentity.gperf"
      {"sigma", 963},
#line 96 "htmlentity.gperf"
      {"egrave", 232},
#line 86 "htmlentity.gperf"
      {"deg", 176},
#line 146 "htmlentity.gperf"
      {"laquo", 171},
      {""},
#line 101 "htmlentity.gperf"
      {"epsilon", 949},
      {""}, {""}, {""},
#line 270 "htmlentity.gperf"
      {"uArr", 8657},
      {""}, {""}, {""}, {""},
#line 71 "htmlentity.gperf"
      {"cedil", 184},
#line 123 "htmlentity.gperf"
      {"hearts", 9829},
      {""}, {""}, {""},
#line 129 "htmlentity.gperf"
      {"iexcl", 161},
#line 265 "htmlentity.gperf"
      {"times", 215},
#line 229 "htmlentity.gperf"
      {"rfloor", 8971},
      {""}, {""}, {""}, {""},
#line 152 "htmlentity.gperf"
      {"lfloor", 8970},
      {""}, {""}, {""},
#line 161 "htmlentity.gperf"
      {"micro", 181},
      {""}, {""}, {""},
#line 224 "htmlentity.gperf"
      {"rArr", 8658},
      {""}, {""}, {""}, {""},
#line 148 "htmlentity.gperf"
      {"lArr", 8656},
      {""}, {""}, {""}, {""},
#line 75 "htmlentity.gperf"
      {"circ", 710},
#line 163 "htmlentity.gperf"
      {"minus", 8722},
      {""}, {""}, {""}, {""}, {""},
#line 274 "htmlentity.gperf"
      {"ugrave", 249},
      {""}, {""}, {""},
#line 278 "htmlentity.gperf"
      {"upsilon", 965},
      {""}, {""}, {""},
#line 61 "htmlentity.gperf"
      {"Auml", 196},
#line 112 "htmlentity.gperf"
      {"forall", 8704},
      {""}, {""}, {""},
#line 139 "htmlentity.gperf"
      {"Iuml", 207},
#line 56 "htmlentity.gperf"
      {"Aring", 197},
      {""}, {""}, {""}, {""},
#line 182 "htmlentity.gperf"
      {"OElig", 338},
#line 195 "htmlentity.gperf"
      {"Oslash", 216},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 95 "htmlentity.gperf"
      {"Egrave", 200},
      {""}, {""},
#line 121 "htmlentity.gperf"
      {"harr", 8596},
#line 100 "htmlentity.gperf"
      {"Epsilon", 917},
#line 273 "htmlentity.gperf"
      {"Ugrave", 217},
      {""}, {""}, {""},
#line 277 "htmlentity.gperf"
      {"Upsilon", 933},
      {""},
#line 228 "htmlentity.gperf"
      {"reg", 174},
#line 232 "htmlentity.gperf"
      {"rlm", 8207},
      {""}, {""},
#line 184 "htmlentity.gperf"
      {"Ograve", 210},
      {""}, {""},
#line 183 "htmlentity.gperf"
      {"oelig", 339},
#line 124 "htmlentity.gperf"
      {"hellip", 8230},
      {""}, {""}, {""},
#line 46 "htmlentity.gperf"
      {"aelig", 230},
#line 168 "htmlentity.gperf"
      {"ndash", 8211},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 244 "htmlentity.gperf"
      {"sim", 8764},
      {""}, {""}, {""}, {""},
#line 291 "htmlentity.gperf"
      {"zwj", 8205},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 45 "htmlentity.gperf"
      {"AElig", 198},
      {""}, {""},
#line 106 "htmlentity.gperf"
      {"eth", 240},
      {""},
#line 243 "htmlentity.gperf"
      {"sigmaf", 962},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 122 "htmlentity.gperf"
      {"hArr", 8660},
      {""},
#line 47 "htmlentity.gperf"
      {"Agrave", 192},
      {""}, {""}, {""}, {""},
#line 130 "htmlentity.gperf"
      {"Igrave", 204},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
#line 160 "htmlentity.gperf"
      {"mdash", 8212},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 276 "htmlentity.gperf"
      {"upsih", 978}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register gint key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
	if (len == lengthtable[key])
	  {
	    register const gchar *s = wordlist[key].name;

	    if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
	      return &wordlist[key];
	  }
    }
  return 0;
}
#line 293 "htmlentity.gperf"

gulong
html_entity_parse (const gchar *s,
                   guint len)
{
	struct _EntityEntry * result = html_entity_hash (s, len);
	if (result == NULL )
		return INVALID_ENTITY_CHARACTER_MARKER;
	return result->value;
}
