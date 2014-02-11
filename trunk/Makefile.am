## Process this file with automake to produce Makefile.in
# Copyright (C) 2011 JoungKyun.Kim <http://oops.org>
#
# This file is part of libipcalc
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# $Id$

ACLOCAL_AMFLAGS = -I m4
DISTCLEANFILES =

EXTRA_DIST = Changes LICENSE debbuild-sh libipcalc.spec \
			debian/patches/01-remove-rpath.patch \
			debian/control \
			debian/compat \
			debian/libipcalc-dev.install \
			debian/libipcalc1.dirs \
			debian/changelog \
			debian/copyright \
			debian/libipcalc1.install \
			debian/libipcalc-utils.dirs \
			debian/rules \
			debian/libipcalc-utils.install \
			debian/libipcalc-dev.dirs

#docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)
if ! COMPAT
dist_doc_DATA = Changes README LICENSE
endif

m4dir = $(datadir)/aclocal
dist_m4_DATA = m4/ipcalc@COMPAT_VERSION@.m4

if COMPAT
BUILT_SOURCE = m4/ipcalc@COMPAT_VERSION@.m4
DISTCLEANFILES += m4/ipcalc@COMPAT_VERSION@.m4

m4/ipcalc@COMPAT_VERSION@.m4:
	mv m4/ipcalc.m4 m4/ipcalc@COMPAT_VERSION@.m4
endif


SUBDIRS = . utils test scripts man

SONAME_MAJOR    = @SONAME_MAJOR@
SONAME_MINOR    = @SONAME_MINOR@
SONAME_REVISION = @SONAME_REVISION@
SONAME_INFO     = @SONAME_INFO@
SONAME_VERSION  = @SONAME_VERSION@

AM_CFLAGS = -Wall
AM_LDFLAGS = -version-info $(SONAME_INFO) @MINGW_CYGWIN_DYNLIB@

include_HEADERS = ipcalc.h
noinst_HEADERS = common.h

lib_LTLIBRARIES = libipcalc@COMPAT_VERSION@.la
libipcalc@COMPAT_VERSION@_la_SOURCES = ipcalc.c

DISTCLEANFILES += *.bz2

if COMPAT
dist-hook:
	mv $(distdir)/libipcalc.spec $(distdir)/libipcalc@COMPAT_VERSION@.spec
endif

if COMPAT
install-data-hook:
	mv $(DESTDIR)$(includedir)/ipcalc.h $(DESTDIR)$(includedir)/ipcalc@COMPAT_VERSION@.h
endif

distclean-local:
	rm -rf autom4te.cache test-install

test-install:
	$(MAKE) DESTDIR=`pwd`/test-install install
