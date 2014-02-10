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

AM_CFLAGS = -Wall
AM_CPPFLAGS = -I$(top_srcdir)
LDADD = ../libipcalc@COMPAT_VERSION@.la

noinst_HEADERS = util.h

bin_PROGRAMS = ip2long@COMPAT_VERSION@
ip2long@COMPAT_VERSION@_SOURCES = ip2long.c

bin_PROGRAMS += netcalc@COMPAT_VERSION@
netcalc@COMPAT_VERSION@_SOURCES = netcalc.c

