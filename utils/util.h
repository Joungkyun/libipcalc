/*
 *  Copyright (c) 2016 JoungKyun.Kim <http://oops.org>
 *
 *  This file is part of libipcalc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILAPI_H
#define UTILAPI_H

#ifdef HAVE_STDBOOL_H
#	include <stdbool.h>
#else
#	ifndef _STDBOOL_H
#		define _STDBOOL_H 1
#		ifndef __STDBOOL_H
#			define __STDBOOL_H 1
#		endif

#		ifndef __cplusplus

#			define bool    _Bool
#			define true    1
#			define false   0

#		else /* __cplusplus */

/* Supporting <stdbool.h> in C++ is a GCC extension.  */
#			define _Bool   bool
#			define bool    bool
#			define false   false
#			define true    true

#		endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#		define __bool_true_false_are_defined   1
#	endif
#endif

void safecpy (char *stor, char *str, int size) {
	size--;
	if ( strlen (str) > size )
		memcpy (stor, str, size);
	else {
		size = strlen (str);
		memcpy (stor, str, size);
	}
	stor[size] = 0;
}

#ifdef _WIN32
	#define IPCALC_WSACleanup WSACleanup()
#else
	#define IPCALC_WSACleanup
#endif

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
