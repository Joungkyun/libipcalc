/*
 * $Id: ipcalc.h,v 1.2 2010-08-07 17:10:13 oops Exp $
 */
#ifndef IPCALC_H
#define IPCALC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#if defined _WIN32 || defined __CYGWIN__
#   include "win95nt.h"
#   ifdef IPCALC_EXPORTS
#       define IPCALC_API __declspec(dllexport)
#   else
#       define IPCALC_API __declspec(dllimport)
#   endif
#else
#   if defined(__GNUC__) && __GNUC__ >= 4
#       define IPCALC_API __attribute__ ((visibility("default")))
#   else
#       define IPCALC_API
#   endif
#endif

#define IPCALC_VERSION "1.0.0"
#define IPCALC_UVERSION "100000000"

/*
 * check valid ip
 */
IPCALC_API short valid_ip_address (char * addr, char * err);

/*
 * Converts a string containing an (IPv4) Internet Protocol
 * dotted address into a proper address
 */
IPCALC_API ulong ip2long (char * ip);

/*
 * Converts IPv4 address into a string in Internet standard dotted format
 * The string is returned in a statically allocated buffer, which subsequent
 * calls will overwrite.
 */
IPCALC_API char * long2ip (ulong ip);

/*
 * Converts IPv4 address into a string in Internet standard dotted format.
 * This is thread safe. dest size is bigger than 16.
 */
IPCALC_API char * long2ip_r (ulong ip, char * dest);

/*
 * convert long netmask to decimical prefix
 * from ipcalc from initscripts on redhat
 */
IPCALC_API short long2prefix (ulong mask);

/*
 * convert network prefix to long mask
 * from ipcalc from initscripts on redhat
 */
IPCALC_API ulong prefix2long (short prefix);

/*
 * return netmask prefix with start ip and end ip
 */
IPCALC_API short guess_prefix (ulong start, ulong end);

/*
 * return netmask with start ip and end ip
 */
IPCALC_API ulong guess_netmask (ulong start, ulong end);

/*
 * return netmask with network and broadcast address
 */
IPCALC_API ulong network (ulong ip, ulong mask);

/*
 * return network
 */
IPCALC_API ulong broadcast (ulong ip, ulong mask);

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
