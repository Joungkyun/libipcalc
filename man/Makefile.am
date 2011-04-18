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

if ! COMPAT
EXTRA_DIST = ko/broadcast.3 ko/guess_netmask.3 ko/ip2long.3 \
		   ko/long2ip.3 ko/long2prefix.3 ko/network.3 \
		   ko/prefix2long.3 ko/valid_ip_address.3 \
		   ko/ip2long.1 ko/netcalc.1
dist_man_MANS = ip2long.1 netcalc.1 broadcast.3 guess_netmask.3 \
				ip2long.3 long2ip.3 long2prefix.3 network.3 \
				prefix2long.3 valid_ip_address.3

ko_man1dir = $(mandir)/ko/man1
ko_man1_DATA = ko/ip2long.1 ko/netcalc.1
ko_man3dir = $(mandir)/ko/man3
ko_man3_DATA = ko/broadcast.3 ko/guess_netmask.3 ko/ip2long.3 \
			   ko/long2ip.3 ko/long2prefix.3 ko/network.3 \
			   ko/prefix2long.3 ko/valid_ip_address.3
endif
