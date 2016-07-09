libipcalc - IPv4 Calculating and subnetting C/C++ APIs
====

## License

Copyright &copy; 2016 JoungKyun.Kim &lt;http://oops.org&gt;. And all rights reserved
LICENSE: [LGPL](/LICENSE)

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

