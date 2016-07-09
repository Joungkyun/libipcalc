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
	const char  * ip1 = "192.168.1.7";
	const char  * ip2 = "192.168.1.10";
	ulong         lmask = 4294967280UL;
	short         prefix = 28;
	short         decfix;
	ulong         decmask;
	int           ret = 0;

	decfix = (ulong) guess_prefix (ip2long ((char *) ip1), ip2long ((char *) ip2));

	if ( decfix == prefix ) {
		printf (
			"PASS:    + guess_netmask (include 192.168.1.7 and 192.168.1.10 => %u)\n",
			prefix
		);
	} else {
		printf (
			"FAIL:    + guess_netmask (include 192.168.1.7 and 192.168.1.10 == %u, but result is %u)\n",
			prefix,
			decfix
		);
		ret = 1;
	}

	decmask = (ulong) guess_netmask (ip2long ((char *) ip1), ip2long ((char *) ip2));

	if ( decmask == lmask ) {
		printf (
			"PASS:    + guess_netmask (include 192.168.1.7 and 192.168.1.10 => %lu)\n",
			lmask
		);
	} else {
		printf (
			"FAIL:    + guess_netmask (include 192.168.1.7 and 192.168.1.10 == %lu, but result is %lu)\n",
			lmask,
			decmask
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
