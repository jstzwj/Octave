/*

Copyright (C) 2016-2017 John W. Eaton

This file is part of Octave.

Octave is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Octave is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

*/

#if ! defined (octave_nproc_wrapper_h)
#define octave_nproc_wrapper_h 1

#if defined __cplusplus
extern "C" {
#endif

enum octave_nproc_query
{
  OCTAVE_NPROC_ALL,
  OCTAVE_NPROC_CURRENT,
  OCTAVE_NPROC_CURRENT_OVERRIDABLE
};

extern unsigned long int
octave_num_processors_wrapper (enum octave_nproc_query);

#if defined __cplusplus
}
#endif

#endif