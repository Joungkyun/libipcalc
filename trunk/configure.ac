# Process this file with autoconf to produce a configure script.
# Configure template for ipcalc library
#
# $Id: configure.ac,v 1.4 2011-01-10 08:06:51 oops Exp $

#
AC_PREREQ(2.59)
AC_INIT([ipcalc], [1.0.0], [http://oops.org])
AC_CONFIG_SRCDIR([ipcalc.h])
AC_CONFIG_HEADER([ipcalc-config.h])
AC_PREFIX_DEFAULT([/usr/local])

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
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

AC_ARG_WITH(compat,
[  --with-compat=VERSION   build compat library])

#AC_PATH_PROG(MAKE, make)
#if test ! -f "$ac_cv_path_MAKE"; then
#	AC_MSG_ERROR(Can't not found make)
#fi

AC_PATH_PROG(PERL, perl)
if test ! -f "$ac_cv_path_PERL"; then
	AC_MSG_ERROR(Can't not found perl)
fi

AC_PATH_PROG(STRIP, strip)
if test ! -f "$ac_cv_path_STRIP"; then
	AC_MSG_ERROR(Can't not found strip)
fi

AC_PATH_PROG(RM, rm)
if test ! -f "$ac_cv_path_RM"; then
	AC_MSG_ERROR(Can't not found rm)
fi

AC_PATH_PROG(HEAD, head)
if test ! -f "$ac_cv_path_HEAD"; then
	AC_MSG_ERROR(Can't not found head)
fi

AC_PATH_PROG(MKDIR, mkdir)
if test ! -f "$ac_cv_path_MKDIR"; then
	AC_MSG_ERROR(Can't not found mkdir)
fi

AC_PATH_PROG(MV, mv)
if test ! -f "$ac_cv_path_MV"; then
	AC_MSG_ERROR(Can't not found mv)
fi

AC_CHECK_LIB(dl, dlopen,,)

if test "x$with_compat" != "x" && test "$with_compat" != "no" ; then
	AC_MSG_CHECKING(for compat library version)
	if test "$with_compat" = "yes"; then
		AC_MSG_ERROR(Don't specify compat library version)
	fi

	compatv=`echo $with_compat | $PERL -pe 's/[[0-9]]//g'`
	if test -n "$compatv"; then
		AC_MSG_ERROR(compat version is only numeric)
	fi
	
	AC_MSG_RESULT([$with_compat])
	COMPAT_VERSION=$with_compat
fi
AC_SUBST(COMPAT_VERSION)

# Checks for header files.
AC_HEADER_STDC

AC_CHECK_HEADERS([arpa/inet.h netinet/in.h sys/socket.h stdbool.h getopt.h])

if test "$GCC" = "yes"; then
	 GCC_MAJOR_VERSION=`$CC --version | $HEAD -n 1 | $PERL -pe 's|^([[^0-9]]*)([[0-9]]+)\..*|\2|g'`
	 if test $GCC_MAJOR_VERSION -ge 4; then
		 CFLAGS="$CFLAGS -fvisibility=hidden"
	 fi
fi

PC_DEFS=`echo $DEFS | perl -pe 's/-DHAVE_CONFIG_H[\s]*//g'`
AC_SUBST(PC_DEFS)

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_HEADER_TIME

AC_CHECK_TYPE([ulong], [AC_DEFINE([C_ULONG_DEFINED], [1], [Define to 1 if the ulong type exists in C.])])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STAT

AC_CONFIG_FILES([Makefile ipcalc.pc ipcalc-config libipcalc.spec])
AC_OUTPUT
