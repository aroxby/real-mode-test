#ifndef _INC_IO_H_
#define _INC_IO_H_

#include "base.h"

ONLYINLINE void out11(unsigned char value, unsigned char port) {
    asm("mov %0, %%al":: "g"(value));
    asm("out %%al, %0": : "g"(port));
}

ONLYINLINE void out12(unsigned char value, unsigned short port) {
    asm("mov %0, %%al": : "g"(value));
    asm("mov %0, %%dx": : "g"(port));
    asm("out %al, %dx");
}

#endif//_INC_IO_H_
