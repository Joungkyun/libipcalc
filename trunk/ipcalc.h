/*
 * $Id$
 */
#ifndef IPCALC_H
#define IPCALC_H

#include <sys/types.h>

/*
 * check valid ip
 */
extern short valid_ip_address (char * addr, char * err);

/*
 * Converts a string containing an (IPv4) Internet Protocol
 * dotted address into a proper address
 */
extern ulong ip2long (char * ip);

/*
 * Converts IPv4 address into a string in Internet standard dotted format
 * The string is returned in a statically allocated buffer, which subsequent
 * calls will overwrite.
 */
extern char * long2ip (ulong ip);

/*
 * Converts IPv4 address into a string in Internet standard dotted format.
 * This is thread safe. dest size is bigger than 16.
 */
extern char * long2ip_r (ulong ip, char * dest);

/*
 * convert long netmask to decimical prefix
 * from ipcalc from initscripts on redhat
 */
extern short long2prefix (ulong mask);

/*
 * convert network prefix to long mask
 * from ipcalc from initscripts on redhat
 */
extern ulong prefix2long (short prefix);

/*
 * return netmask prefix with start ip and end ip
 */
extern short guess_prefix (ulong start, ulong end);

/*
 * return netmask with start ip and end ip
 */
extern ulong guess_netmask (ulong start, ulong end);

/*
 * return netmask with network and broadcast address
 */
extern ulong network (ulong ip, ulong mask);

/*
 * return network
 */
extern ulong broadcast (ulong ip, ulong mask);

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
