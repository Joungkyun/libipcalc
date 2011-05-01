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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#if defined _WIN32 || defined __CYGWIN__
	#include "win95nt.h"
	#ifdef IPCALC_EXPORTS
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

#define IPCALC_VERSION "1.0.1-dev"
#define IPCALC_UVERSION "001000001-dev"

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
