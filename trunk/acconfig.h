#ifndef IPCALC_CONFIG_H
#define IPCALC_CONFIG_H

#ifdef PACKAGE_BUGREPORT
#	undef IPCALC_PACKAGE_BUGREPORT
#endif

#ifdef PACKAGE_NAME
#	undef IPCALC_PACKAGE_NAME
#endif

#ifdef PACKAGE_STRING
#	undef IPCALC_PACKAGE_STRING
#endif

#ifdef PACKAGE_TARNAME
#	undef IPCALC_PACKAGE_TARNAME
#endif

#ifdef PACKAGE_VERSION
#	undef IPCALC_PACKAGE_VERSION
#endif

/* config.h:  a general config file */

@TOP@

@BOTTOM@


/*
 * Compotable C Type
 */

#if ! defined C_ULONG_DEFINED
	typedef	unsigned long	ulong;
#endif

#endif /* IPCALC_CONFIG_H */
