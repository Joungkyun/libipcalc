/*
 * $Id: util.h,v 1.1.1.1 2010-08-07 16:27:50 oops Exp $
 */
#ifndef UTILAPI_H
#define UTILAPI_H

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
