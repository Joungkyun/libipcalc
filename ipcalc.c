/*
 * $Id: ipcalc.c,v 1.1.1.1 2010-08-07 16:27:49 oops Exp $
 */

/*
 * IPCALC (IP calculationg and subnetting library)
 *
 * This library support API for IP calculating and subnetting.
 * License: LGPL
 *
 * Copyright (c) 2010 JoungKyun.Kim <http://oops.org>
 */

#ifdef HAVE_CONFIG_H
#   include <ipcalc-config.h>
#endif

#include <ipcalc.h>

/*
 * check valid ip
 */
IPCALC_API short valid_ip_address (char * addr, char * err) { // {{{
	struct addrinfo hints, * r, * rp;
	struct sockaddr_in *sin;
	//struct sockaddr_in6 *sin6;
	int stat;
	char buf[256] = { 0, };

	memset (err, 0, 1);
	memset (&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;

	if ( (stat = getaddrinfo (addr, NULL, &hints, &r)) != 0 ) {
		strcpy (err, gai_strerror (stat));
		memset (addr, 0, strlen (addr));
		return 1;
	}

	memset (addr, 0, strlen (addr));
	for ( rp = r; rp != NULL; rp = rp->ai_next ) {
		switch ( rp->ai_family ) {
			case AF_INET :
				sin = (void *) rp->ai_addr;
				inet_ntop (rp->ai_family, &sin->sin_addr, buf, sizeof (buf));
				strcpy (addr, buf);
				freeaddrinfo (r);
				return 0;
				break;
			case AF_INET6 :
				/*
				sin6 = (void *) rp->ai_addr;
				inet_ntop (rp->ai_family, &sin6->sin6_addr, buf, sizeof (buf));
				strcpy (addr, buf);
				*/
				strcpy (err, "This is IPv6 address");
				freeaddrinfo (r);
				return 1;
				break;
		}
	}

	freeaddrinfo (r);

	return 1;
} // }}}

/*
 * Converts a string containing an (IPv4) Internet Protocol
 * dotted address into a proper address
 */
IPCALC_API ulong ip2long (char * ip) { // {{{
	struct in_addr s;

	if ( ! strlen (ip) || ! inet_aton (ip, &s) )
		return 0;

	return ntohl (s.s_addr);
} // }}}

/*
 * Converts IPv4 address into a string in Internet standard dotted format
 * The string is returned in a statically allocated buffer, which subsequent
 * calls will overwrite.
 */
IPCALC_API char * long2ip (ulong num) { // {{{
	struct in_addr	addr;

	/*
	* if num is charactor type, add follow line
	* n = strtoul (num, NULL, 0);
	*/
	addr.s_addr = htonl (num);
	return inet_ntoa (addr);
} // }}}

/*
 * Converts IPv4 address into a string in Internet standard dotted format.
 * This is thread safe. dest size is bigger than 16.
 */
IPCALC_API char * long2ip_r (ulong num, char * dest) { // {{{
	short ip[4] = { 0, 0, 0, 0 };
	short i;

	memset (dest, 0, 16);

	for ( i=3; i>=0; i--) {
		ip[i] = num % 256;
		num /= 256;
	}

	sprintf (dest, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
	return dest;
} // }}}

#define IPBITS (sizeof(u_int32_t) * 8)
/*
 * convert long netmask to decimical prefix
 * from ipcalc from initscripts on redhat
 */
IPCALC_API short long2prefix (ulong mask) { // {{{
	int	i;
	int	count = IPBITS;

	for (i = 0; i < IPBITS; i++) {
		if (!(mask & ((2 << i) - 1)))
			count--;
	}

	return count;
} // }}}

/*
 * convert network prefix to long mask
 * from ipcalc from initscripts on redhat
 */
IPCALC_API ulong prefix2long (short n) { // {{{
	short	l = 32;
	short   shift = 30;
	ulong	v = 0;

	n = 32 - n;

	while (l > n) {
		if ( shift < 0 )
			v += 1;
		else
			v += (2 << shift);

		shift--;
		l--;
	}

	return v;
} // }}}

/*
 * return netmask prefix with start ip and end ip
 */
IPCALC_API short guess_prefix (ulong s, ulong e) { // {{{
	ulong	n;
	short	prefix = 0;

	// If end is bigger than start, reverse between start and end.
	if ( e < s ) {
		n = s;
		s = e;
		e = n;
	}

	n = e - s;
	if ( n == 0 )
		return 32;

	while ( ! (n & 0x80000000) ) {
		n <<= 1;
		prefix++;
	}

	// If brocast is smaller than end, decrease prefix.
	n = 0;
	while ( e > n ) {
		if ( n > 0 )
			prefix--;

		n = broadcast (s, prefix2long (prefix));
	}

	return prefix;
} // }}}

/*
 * return netmask with start ip and end ip
 */
IPCALC_API ulong guess_netmask (ulong s, ulong e) { // {{{
	return prefix2long (guess_prefix (s, e));
} // }}}

/*
 * return netmask with network and broadcast address
 *
IPCALC_API ulong netmask (ulong net, ulong bcast) { // {{{
	return net + 0x80000000 - bcast;
} // }}}
*/

/*
 * return network
 */
IPCALC_API ulong network (ulong ip, ulong mask) { // {{{
	return ip & mask;
} // }}}

/*
 * return broadcast
 */
IPCALC_API ulong broadcast (ulong ip, ulong mask) { // {{{
	return (ip & mask) | ~(mask);
} // }}}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
