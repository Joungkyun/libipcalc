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
	const char  * net = "192.168.1.0";
	const char  * bcast = "192.168.1.15";
	ulong         lmask = 4294967280UL;
	short         prefix = 28;
	char          rip[16] = { 0, };
	int           ret = 0;

	if ( strcmp (long2ip_r (network (ip2long((char *) ip1), lmask), rip), net) == 0 ) {
		printf (
			"PASS:    + network (%s/%u => %s)\n",
			ip1,
			prefix,
			rip	
		);
	} else {
		printf (
			"FAIL:    + network (%s/%u == %s, but result is %s)\n",
			ip1,
			prefix,
			net,
			rip	
		);
		ret = 1;
	}

	if ( strcmp (long2ip_r (broadcast (ip2long((char *) ip1), lmask), rip), bcast) == 0 ) {
		printf (
			"PASS:    + broadcast (%s/%u => %s)\n",
			ip1,
			prefix,
			rip	
		);
	} else {
		printf (
			"FAIL:    + broadcast (%s/%u == %s, but result is %s)\n",
			ip1,
			prefix,
			bcast,
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
