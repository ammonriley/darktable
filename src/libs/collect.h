/*
    This file is part of darktable,
    copyright (c) 2009--2011 johannes hanika.
    copyright (c) 2012 henrik andersson.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/

typedef enum dt_lib_collect_mode_t
{
  DT_LIB_COLLECT_MODE_AND=0,
  DT_LIB_COLLECT_MODE_OR,
  DT_LIB_COLLECT_MODE_AND_NOT
}
dt_lib_collect_mode_t;

const char *dt_lib_collect_string[] =
{
  N_("film roll"),
  N_("camera"),
  N_("tag"),
  N_("date"),
  N_("history"),
  N_("color label"),
  N_("title"),
  N_("description"),
  N_("creator"),
  N_("publisher"),
  N_("rights"),
  N_("lens"),
  N_("iso"),
  N_("aperture"),
  N_("filename")
};
const int dt_lib_collect_string_cnt = 15;

