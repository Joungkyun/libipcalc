IPv4 Calculating and subnetting C/C++ APIs
====
[![Build Status](https://travis-ci.org/Joungkyun/libipcalc.svg?branch=master)](https://travis-ci.org/Joungkyun/libipcalc) [![GitHub license](https://img.shields.io/badge/license-LGPLv2-blue.svg)](https://raw.githubusercontent.com/Joungkyun/libipcalc/master/LICENSE)

## License

Copyright &copy; 2016 JoungKyun.Kim &lt;http://oops.org&gt;. And all rights reserved

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE as published
by the Free Software Foundation; either version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU LESSER GENERAL PUBLIC LICENSE for more details.

You should have received a copy of the GNU LESSER GENERAL PUBLIC LICENSE
along with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

This library is forked in [libkrisp](https://github.com/Joungkyun/libkrisp).

## Description

libipcalc is a C/C++ library to subnetting and calcaulating IPv4.

You can work follow job with this library:

  * calculating subnet mask
  * calculation broadcast
  * calcualtion prefix of subnet mask
  * converting dotted IPv4 address to 32bit decimal ip address
  * converting 32bit decimal subnet mask and prefix of subnet mask
  * calculating minimum subnet maks that containes 2 IPv4 address.


## Installation

use autotools system.

```bash
[root@host libipcalc-1.0.3]$ ./configure --prefix=/path
[root@host libipcalc-1.0.3]$ make
[root@host libipcalc-1.0.3]$ make install
```

For preinstall, use DESTDIR environment as follows:

```bash
[root@host libipcalc-1.0.3]$ make install DESTDIR=/path
```

## Usage

See also [Wiki pages](https://github.com/Joungkyun/libipcalc/wiki) about C/C++ apis and utility commands.
