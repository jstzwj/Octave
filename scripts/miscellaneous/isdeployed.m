## Copyright (C) 2012-2017 John W. Eaton
##
## This file is part of Octave.
##
## Octave is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Octave is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Octave; see the file COPYING.  If not, see
## <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {} isdeployed ()
## Return true if the current program has been compiled and is running
## separately from the Octave interpreter and false if it is running in
## the Octave interpreter.
##
## Currently, this function always returns false in Octave.
## @end deftypefn

function retval = isdeployed ()
  retval = false;
endfunction


%!assert (isdeployed (), false)