/*
 * $Id$
 */

/*
 * IPCALC (IP calculationg and subnetting library)
 *
 * This library support API for IP calculating and subnetting.
 * License: LGPL
 *
 * Copyright (c) 2010 JoungKyun.Kim <http://oops.org>
 */

#ifndef COMMON_H
#define COMMON_H

#if defined _WIN32
#define WINVER 0x0501 // WindowsXP
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#if defined _WIN32
	#include <ws2tcpip.h>

	// Don't understand Code::Blocs. It's use MSVS
	//#pragma comment(lib, "ws2_32.lib")

	typedef uint32_t u_int32_t;
	typedef unsigned long ulong;
	const char * inet_ntop (int, const void *, char *, socklen_t);
	int inet_pton (int, const char *, void *);
	int inet_aton (const char * op, struct in_addr * inp);
#else
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <netdb.h>
#endif

#if defined _WIN32 || defined __CYGWIN__
	#ifdef HAVE_DLL_EXPORT
		#define IPCALC_API __declspec(dllexport)
	#else
		#define IPCALC_API __declspec(dllimport)
	#endif
#else
	#if HAVE_VISIBILITY
		#define IPCALC_API __attribute__ ((visibility("default")))
	#else
		#define IPCALC_API
	#endif
#endif

#define IPCALC_VERSION "1.0.3"
#define IPCALC_UVERSION "001000003"

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
