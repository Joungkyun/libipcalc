/*
 *  Copyright (c) 2016 JoungKyun.Kim <http://oops.org/>. All rights reserved.
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

#define IPCALC_VERSION "1.0.4"
#define IPCALC_UVERSION "001000004"

#ifdef UINT_MAX
	#undef UINT_MAX
#endif
#define UINT_MAX 4294967296U

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
