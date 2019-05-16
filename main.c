/*
This instruction (while making the code more readable) is not needed if we are careful.
I was tempted to leave it in for clarity but this projects intention to achieve full parity
with hand written assembly.  I leave it here for reference.
asm("jmp main");
*/

#include "io.h"
#include "qemu.h"

ONLYINLINE void serial_write(char ch);
ONLYINLINE void stop();
ONLYINLINE void hlt();
ONLYINLINE void cli();

void boot() {
    serial_write('*');
    stop();
}

ONLYINLINE void serial_write(char ch) {
    const static unsigned short COM1_PORT = 0x3F8;
    out12(ch, COM1_PORT);
}

ONLYINLINE void stop() {
    qemu_quit(0);
    cli();
    while(1) {
        hlt();
    }
}

ONLYINLINE void cli() {
    asm("cli");
}

ONLYINLINE void hlt() {
    asm("hlt");
}
