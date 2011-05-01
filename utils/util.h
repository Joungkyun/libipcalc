/*
 * $Id$
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

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
