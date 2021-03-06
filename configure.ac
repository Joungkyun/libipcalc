# Process this file with autoconf to produce a configure script.
# Configure template for ipcalc library
#

#
AC_PREREQ(2.59)
AC_INIT([libipcalc], [1.0.4], [https://github.com/Joungkyun/libipcalc])
AC_CONFIG_AUX_DIR([tools])
AM_INIT_AUTOMAKE([-Wall -Werror -Wno-override foreign no-dependencies])
AM_MAINTAINER_MODE

AC_CONFIG_SRCDIR([ipcalc.h])
AC_CONFIG_HEADER([ipcalc-config.h])
AC_PREFIX_DEFAULT([/usr/local])

AC_DEFUN([AC_DATAROOTDIR_CHECKED])

AC_SUBST(SONAME_INFO)
AC_SUBST(SONAME_VERSION)
AC_SUBST(SONAME_MAJOR)
AC_SUBST(SONAME_MINOR)
AC_SUBST(SONAME_REVISION)

SONAME_MAJOR=1
SONAME_MINOR=0
SONAME_REVISION=0
SONAME_VERSION=$SONAME_MAJOR.$SONAME_MINOR.$SONAME_REVISION

SONAME_VALUE=$(($SONAME_MAJOR + $SONAME_MINOR))
SONAME_INFO="$SONAME_VALUE:$SONAME_REVISION:$SONAME_MINOR"

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AX_GL_VISIBILITY
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_LIB_RPATH

AC_PATH_PROG(PERL, perl)
if test ! -f "$ac_cv_path_PERL"; then
	AC_MSG_ERROR(Can't not found perl)
fi

AC_PATH_PROG(DATE, date)
if test ! -f "$ac_cv_path_DATE"; then
	AC_MSG_ERROR(Can't not found date)
fi


AC_SUBST(PACKAGE_DATE)
PACKAGE_DATE=$($DATE +"%a %b %d %Y")

AX_COMPAT_OPTION

# Checks for libraries.
AC_CHECK_LIB(dl, dlopen,,)

if test "x$lt_prog_compiler_pic" = "x-DDLL_EXPORT"; then
	LIBS="$LIBS -no-undefined"
fi

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h sys/socket.h stdbool.h getopt.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_SIZE_T
AC_HEADER_TIME

AC_CHECK_TYPE([ulong], [AC_DEFINE([C_ULONG_DEFINED], [1], [Define to 1 if the ulong type exists in C.])])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STAT

case $host_os in
  mingw*)
    AC_DEFINE(HAVE_LIBWS2_32, 1, [Define to 1 if you have the 'ws2_32' library (-lws2_32).])
    AC_SUBST(MING_WS2_32_LIBS)
	MING_WS2_32_LIBS="-lws2_32"
	;;
esac

AX_STATIC_BINDIR
AC_CONFIG_FILES([
	Makefile
	man/Makefile
	scripts/Makefile
	scripts/ipcalc.pc
	scripts/ipcalc-config
	test/Makefile
	utils/Makefile
	m4/ipcalc.m4
	libipcalc.spec
])
AC_OUTPUT
