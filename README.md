# PINKIE SSCANF

This module contains the sscanf-implementation of PINKIE. It can be used
separately to add a minimal number-parsing sscanf-functionality.

It currently supports the following patterns:
  * %i - signed integers
  * %u - unsigned integers
  * %x - hex values
  * %% - percent sign
  * %n - store current position in pointer
  * maximum field width

This implementation supports up to 64-bit numbers which can be configured by
the define PINKIE\_CFG\_SSCANF\_MAX\_INT:

  * PINKIE\_CFG\_SSCANF\_MAX\_INT == 1: 8 bit numbers
  * PINKIE\_CFG\_SSCANF\_MAX\_INT == 2: 8 to 16 bit numbers
  * PINKIE\_CFG\_SSCANF\_MAX\_INT == 4: 8 to 32 bit numbers
  * PINKIE\_CFG\_SSCANF\_MAX\_INT == 8: 8 to 64 bit numbers (default)

Tested on:
  - Atmel ATmega328P (8-bit uC, used in Arduino Nano)
  - Linux 32 Bit
  - Linux 64 Bit
