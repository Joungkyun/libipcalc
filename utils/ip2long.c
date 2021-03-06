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

#ifdef HAVE_CONFIG_H
#   include <ipcalc-config.h>
#endif

#include <common.h>
#include <ipcalc.h>

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#define PNAME "ip2long"
#define LONGIP 0
#define IPv4 1

#ifdef HAVE_GETOPT_LONG
static struct option long_options [] = { // {{{
	/* Options without arguments: */
	{ "help",       no_argument,       NULL, 'h' },
	{ "verbose",    no_argument,       NULL, 'v' },

	/* Options accepting an argument: */
	//{ "datafile", required_argument, NULL, 'f' },
	{ 0, 0, 0, 0 }
}; // }}}
#endif

#include <util.h>

void usage (char * prog) { // {{{
	fprintf (stderr, "%s v%s: Convert between IPv4 address and Long IP\n", prog, IPCALC_VERSION);
	fprintf (stderr, "Usage: %s [option] ip-address|LongIP\n", prog);
	fprintf (stderr, "Options:\n");
	fprintf (stderr, "         -h, --help             print this message\n");
	fprintf (stderr, "         -v, --verbose          print both long ip and ipv4\n");

	exit (1);
} // }}}

int main (int argc, char ** argv) {
	char 			ip[256] = { 0, };
	char			oip[256] = { 0, };
	char			err[1024];
	int				opt;
	bool			verbose = false;
	short			input;

#ifdef HAVE_GETOPT_LONG
	while ( (opt = getopt_long (argc, argv, "hv", long_options, (int *) 0)) != EOF ) {
#else
	while ( (opt = getopt (argc, argv, "hv")) != EOF ) {
#endif
		switch (opt) {
			case 'v' :
				verbose = true;
				break;
			default:
				usage (PNAME);
		}
	}

	if ( argc - optind < 1 || argc == 1 ) {
		usage (PNAME);
		return 1;
	}

	safecpy (ip, argv[optind], 256);
	input = (strchr (ip, '.') != NULL) ? IPv4 : LONGIP;

#ifdef _WIN32
	{
		WORD wVerReq = MAKEWORD (2, 2); // WinSock 2.2 요청
		WSADATA wsaData;
		int nErrStatus;

		if ( (nErrStatus = WSAStartup (wVerReq, &wsaData)) != 0 ) {
			fprintf (stderr, "ERROR: Failed initialize WSAStart\n");
			return 1;
		}
	}
#endif

	strcpy (oip, ip);
	if ( valid_ip_address (ip, err) ) {
		fprintf (stderr, "ERROR: %s -> %s\n", oip, err);
		IPCALC_WSACleanup;
		return 1;
	}

	if ( verbose )
		printf ("IPv4   : ");
	if ( verbose || input == LONGIP )
		printf ("%s\n", ip);

	if ( verbose )
		printf ("LONGIP : ");
	if ( verbose || input == IPv4 )
		printf ("%lu\n", ip2long (ip));

	IPCALC_WSACleanup;

	return 0;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
