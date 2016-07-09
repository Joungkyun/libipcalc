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
#include <ipcalc.h>

int main (void) {
	const char  * ip = "10.0.0.4";
	ulong         lip = 167772164UL;
	char        * rip;
	ulong         longip;
	int           ret = 0;

	if ( (longip = ip2long ((char *) ip)) == lip )
		printf (
			"PASS:    + ip2long (%s -> %lu)\n",
			ip,
			longip
		);
	else {
		printf (
			"FAIL:    + ip2long (%ip == %lu, but result is %lu)\n",
			ip,
			lip,
			longip
		);
		ret = 1;
	}

	if ( strcmp ((rip = long2ip (lip)), ip) == 0 )
		printf (
			"PASS:    + long2ip (%lu -> %s)\n",
			lip,
			rip
		);
	else {
		printf (
			"FAIL:    + long2ip (%lu == %s, but result is %s)\n",
			lip,
			ip,
			rip
		);
		ret = 1;
	}

	// thread safe api
	if ( strcmp ((long2ip_r (lip, rip)), ip) == 0 )
		printf (
			"PASS:    + long2ip_r (%lu -> %s)\n",
			lip,
			rip
		);
	else {
		printf (
			"FAIL:    + long2ip (%lu == %s, but result is %s)\n",
			lip,
			ip,
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
