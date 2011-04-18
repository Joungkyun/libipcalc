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

# $Id: Makefile.am,v 1.6 2011-04-12 16:36:35 oops Exp $

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = Changes LICENSE debbuild-sh libipcalc.spec \
			debian/patches/01-remove-rpath.patch \
			debian/control \
			debian/compat \
			debian/libipcalc-dev.install \
			debian/libipcalc1.dirs \
			debian/changelog \
			debian/copyright \
			debian/libipcalc1.install \
			debian/ipcalc-utils.dirs \
			debian/rules \
			debian/ipcalc-utils.install \
			debian/libipcalc-dev.dirs

if ! COMPAT
docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)
dist_doc_DATA = Changes README LICENSE
endif

#m4dir = $(datadir)/aclocal
#dist_m4_DATA = m4/ipcalc@COMPAT_VERSION@.m4

#if COMPAT
#BUILT_SOURCE = m4/ipcalc@COMPAT_VERSION@.m4
#DISTCLEANFILES = m4/ipcalc@COMPAT_VERSION@.m4
#
#m4/ipcalc@COMPAT_VERSION@.m4:
#	mv m4/ipcalc.m4 m4/ipcalc@COMPAT_VERSION@.m4
#endif


SUBDIRS = . utils test scripts man

SONAME_MAJOR    = @SONAME_MAJOR@
SONAME_MINOR    = @SONAME_MINOR@
SONAME_REVISION = @SONAME_REVISION@
SONAME_INFO     = @SONAME_INFO@
SONAME_VERSION  = @SONAME_VERSION@

AM_CFLAGS = -Wall
AM_LDFLAGS = -version-info $(SONAME_INFO)

include_HEADERS = ipcalc.h
noinst_HEADERS = common.h

lib_LTLIBRARIES = libipcalc@COMPAT_VERSION@.la
libipcalc@COMPAT_VERSION@_la_SOURCES = ipcalc.c

dist-hook:
	$(PERL) -pi -e \
			"s/\@PACKAGE_VERSION\@/$(VERSION)/g" \
			$(distdir)/$(PACKAGE).spec
	$(PERL) -pi -e \
			"s/\@PACKAGE_DATE\@/$(PACKAGE_DATE)/g" \
			$(distdir)/$(PACKAGE).spec

if COMPAT
install-data-hook:
	mv $(DESTDIR)$(includedir)/ipcalc.h $(DESTDIR)$(includedir)/ipcalc@COMPAT_VERSION@.h
endif
