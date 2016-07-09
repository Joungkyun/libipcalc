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
	char          rip[16] = { 0, };
	char          err[1024];
	int           ret = 0;

	strcpy (rip, "256.0.0.1");
	if ( valid_ip_address (rip, err) != 0 ) {
		printf (
			"PASS:    + valid_ip_address (%s => %s)\n",
			rip,
			err
		);
	} else {
		printf (
			"PASS:    + valid_ip_address (%s => must occur error. but no error!)\n",
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
