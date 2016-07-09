/*
 * Copyright (c) 2016 JoungKyun.Kim <http://oops.org/>
 *
 * This file is part of libipcalc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>. 
 */

#include <stdio.h>
#include <string.h>
#include <ipcalc.h>

int main (void) {
	ulong         lmask = 4294967280UL;
	short         prefix = 28;
	short         decfix;
	ulong         decmask;
	int           ret = 0;

	decmask = prefix2long (prefix);
	if ( decmask == lmask ) {
		printf (
			"PASS:    + prefix2long (prefix %u => %lu)\n",
			prefix,
			decmask
		);
	} else {
		printf (
			"FAIL:    + prefix2long (prefix %u == %lu, but result is %lu)\n",
			prefix,
			lmask,
			decmask
		);
		ret = 1;
	}

	decfix = long2prefix (lmask);
	if ( decfix == prefix ) {
		printf (
			"PASS:    + long2prefix (decimal ip %lu => %u)\n",
			lmask,
			decfix
		);
	} else {
		printf (
			"FAIL:    + long2prefix (decimal ip %lu == %u, but result is %u)\n",
			lmask,
			prefix,
			decfix
		);
		ret = 1;
	}

	return ret;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
