Calculator programs and source for MA1473 & MA1474
======

These are installed to the calculator by transferring the `.8xp` and `.8xv` files available in each respective `bin` folder to a supported device. This is usually done by using the software 'TI Connect' for your specific calculator. To build or modify the source, the [CE-Programming toolkit](https://github.com/CE-Programming/toolchain) is needed.

All programs except `Hill` are written in C using the aforementioned toolkit.

More information is found in each respective README.

__NOTE!__
Not all numbers will evaluate correctly. The largest value is an unsigned long int (32 bits), 4 294 967 296. If any step is above that number, intermediate results may be inaccurate due to overflow. This cannot be solved simply due to the fact that there is no arbitary sized numbers available on the calculator.
