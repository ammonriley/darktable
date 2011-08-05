/*
    This file is part of darktable,
    copyright (c) 2011 johannes hanika.

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
#ifndef DT_IMAGE_CACHE_H
#define DT_IMAGE_CACHE_H

#include "common/cache.h"

typedef struct dt_image_cache_t
{
  // TODO: one fat block of dt_image_t, to assign `dynamic' void* in cache to.
  dt_cache_t cache;
}
dt_image_cache_t;

// blocks until it gets the image struct with this id for reading.
// also does the sql query if the image is not in cache atm.
// if id < 0, a newly wiped image struct shall be returned (for import).
// this will silently start the garbage collector and free long-unused
// cachelines to free up space if necessary.
// if an entry is swapped out like this in the background, this is the latest
// point where sql and xmp can be synched (unsafe setting).
const dt_image_t *dt_image_cache_read_get(const int32_t id);
// drops the read lock on an image struct
void              dt_image_cache_read_release(const dt_image_t *img);
// augments the already acquired read lock on an image to write the struct.
// blocks until all readers have stepped back from this image (all but one,
// which is assumed to be this thread)
dt_image_t       *dt_image_cache_write_get(const dt_image_t *img);
// drops the write priviledges on an image struct.
// thtis triggers a write-through to sql, and if the setting
// is present, also to xmp sidecar files (safe setting).
void              dt_image_cache_write_release(dt_image_t *img);

#endif