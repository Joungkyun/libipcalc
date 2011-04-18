/*
 * Copyright (C) 2011 JoungKyun.Kim <http://oops.org/>
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
 *
 * $Id: $
 */

#include <stdio.h>
#include <ipcalc.h>

int main (void) {
	const char	* ip = "10.0.0.4";
	char		* rip;
	ulong		longip;
	int			ret = 0;

	if ( (longip = ip2long (ip)) == 167772164UL )
		printf ("PASS:    + ip2long (10.0.0.4 -> 167772164UL)\n");
	else {
		printf (
			"FAIL:    + ip2long (10.0.0.4 == 167772164UL, but result is %ld)\n",
			longip
		);
		ret = 1;
	}

	if ( strcmp ((rip = long2ip (167772164UL)), "10.0.0.4") == 0 )
		printf ("PASS:    + long2ip (167772164UL -> 10.0.0.4)\n");
	else {
		printf (
			"FAIL:    + long2ip (167772164UL == 10.0.0.4, but result is %s)\n",
			rip
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
