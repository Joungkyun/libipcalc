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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#define PNAME "netcalc"
#define CIDS 0
#define IPv4 1

#ifdef HAVE_GETOPT_LONG
static struct option long_options [] = { // {{{
	/* Options without arguments: */
	{ "broadcast",    no_argument,       NULL, 'b' },
	{ "help",         no_argument,       NULL, 'h' },
	{ "mask",         no_argument,       NULL, 'm' },
	{ "network",      no_argument,       NULL, 'n' },
	{ "prefix",       no_argument,       NULL, 'p' },
	{ "shell-format", no_argument,       NULL, 's' },
	{ "verbose",      no_argument,       NULL, 'v' },

	/* Options accepting an argument: */
	//{ "datafile",   required_argument, NULL, 'f' },
	{ 0, 0, 0, 0 }
}; // }}}
#endif

void usage (char * prog) { // {{{
	fprintf (stderr, "%s v%s: get network informations\n", prog, IPCALC_VERSION);
	fprintf (stderr, "Usage: %s [option] ipaddress/[mask|prefix]\n", prog);
	fprintf (stderr, "       %s [option] StartIP EndIP\n", prog);
	fprintf (stderr, "Options:\n");
	fprintf (stderr, "         -h, --help             print this message\n");
	fprintf (stderr, "         -b, --broadcast        print broadcast\n");
	fprintf (stderr, "         -n, --network          print network\n");
	fprintf (stderr, "         -m, --mask             print network mask\n");
	fprintf (stderr, "         -p, --prefix           print network prefix\n");
	fprintf (stderr, "         -s, --shell-format     print shell format\n");
	fprintf (stderr, "         -a, --all              print all\n");

	exit (1);
} // }}}

typedef struct opt_value {
	short	broadcast;
	short	mask;
	short	network;
	short	prefix;
	short	shell;
} OPTV;

typedef struct resutls_value {
	ulong	start;
	ulong	end;
	short	prefix;
	ulong	mask;
	ulong	network;
	ulong	broadcast;
} RETV;

#include <util.h>

int main (int argc, char ** argv) {
	char 	ip[256] = { 0, };
	char	err[1024];
	char *	postfix;
	char *	pformat;
	int		opt;
	short	optno;
	bool	verbose = false;
	OPTV	optv;
	RETV	r;

	optv.broadcast = 0;
	optv.mask      = 0;
	optv.network   = 0;
	optv.prefix    = 0;
	optv.shell     = 0;

#ifdef HAVE_GETOPT_LONG
	while ( (opt = getopt_long (argc, argv, "abhnmpsv", long_options, (int *) 0)) != EOF ) {
#else
	while ( (opt = getopt (argc, argv, "abhnmpsv")) != EOF ) {
#endif
		switch (opt) {
			case 'v' :
				verbose = true;
				break;
			case 'a' :
				optv.broadcast++;
				optv.mask++;
				optv.network++;
				optv.prefix++;
				break;
			case 'b' :
				optv.broadcast++;
				break;
			case 'm' :
				optv.mask++;
				break;
			case 'n' :
				optv.network++;
				break;
			case 'p' :
				optv.prefix++;
				break;
			case 's' :
				optv.shell++;
				break;
			default:
				usage (PNAME);
		}
	}

	if ( optv.shell )
		verbose = false;

	optno = argc - optind;
	if ( optno < 1 || optno > 2 ) {
		usage (PNAME);
		return 1;
	}

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

	if ( optno == 1 ) {
		/*
		 * Case IP/Prefix or IP/Netmask
		 */
		char *	mask;
		char	_mask[256] = { 0, };

		safecpy (ip, argv[optind], 256);
		if ( (mask = strchr (ip, '/')) == NULL ) {
			fprintf (stderr, "ERROR: %s format is IPADDRESS/[NETMASK|PREFIX]\n", argv[1]);
			usage (PNAME);
			IPCALC_WSACleanup;
			return 1;
		}
		safecpy (_mask, mask + 1, 256);
		*mask = 0;

		if ( valid_ip_address (ip, err) ) {
			fprintf (stderr, "ERROR: %s -> %s\n", ip, err);
			IPCALC_WSACleanup;
			return 1;
		}
		r.start = ip2long (ip);

		if ( strchr (_mask, '.') ) {
			if ( valid_ip_address (_mask, err) ) {
				fprintf (stderr, "ERROR: %s -> %s\n", _mask, err);
				IPCALC_WSACleanup;
				return 1;
			}

			r.mask = ip2long (_mask);
			r.prefix = long2prefix (r.mask);
		} else {
			r.prefix = atoi (_mask);
			if ( r.prefix > 32 || r.prefix < 0 ) {
				fprintf (stderr,
						"ERROR: %s is overflow or underflow on prefix range.\n",
						_mask
				);
				IPCALC_WSACleanup;
				return 1;
			}
			r.mask = prefix2long (r.prefix);
		}

		r.network = network (r.start, r.mask);
		r.broadcast = r.end = broadcast (r.start, r.mask);
	} else {
		/*
		 * Case given range from start ip to end ip
		 */
		if ( strchr (argv[optind], '/') != NULL ||
			strchr (argv[optind + 1], '/') != NULL ) {
			fprintf (
				stderr,
				"ERROR: %s and %s is must ip address\n",
				argv[optind],
				argv[optind + 1]
			);
			usage (PNAME);
			IPCALC_WSACleanup;
			return 1;
		}

		safecpy (ip, argv[optind], 256);
		if ( valid_ip_address (ip, err) ) {
			fprintf (stderr, "ERROR: %s -> %s\n", ip, err);
			IPCALC_WSACleanup;
			return 1;
		}
		r.start = ip2long (ip);

		safecpy (ip, argv[optind + 1], 256);
		if ( valid_ip_address (ip, err) ) {
			fprintf (stderr, "ERROR: %s -> %s\n", ip, err);
			IPCALC_WSACleanup;
			return 1;
		}
		r.end = ip2long (ip);

		if ( r.end < r.start ) {
			r.mask = r.start;
			r.start = r.end;
			r.end = r.mask;
		}

		r.prefix = guess_prefix (r.start, r.end);
		r.mask = prefix2long (r.prefix);
		r.network = network (r.start, r.mask);
		r.broadcast= broadcast (r.start, r.mask);
	}

	postfix = optv.shell ? "=" : " : ";
	pformat = optv.shell ? "%s%s" : "%-11s%s";

	if ( verbose ) {
		printf ("%-11s : %s - ", "GIVEN RANGE", long2ip (r.start));
		printf ("%s\n", long2ip (r.end));
	}

	if ( optv.network ) {
		if ( verbose || optv.shell )
			printf (pformat, "NETWORK", postfix);

		printf ("%s\n", long2ip (r.network));
	}

	if ( optv.broadcast ) {
		if ( verbose || optv.shell )
			printf (pformat, "BROADCAST", postfix);

		printf ("%s\n", long2ip (r.broadcast));
	}

	if ( optv.mask ) {
		if ( verbose || optv.shell )
			printf (pformat, "NETMASK", postfix);

		printf ("%s\n", long2ip (r.mask));
	}

	if ( optv.prefix ) {
		if ( verbose || optv.shell )
			printf (pformat, "PREFIX", postfix);

		printf ("%d\n", r.prefix);
	}

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
