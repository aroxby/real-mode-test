#include "io.h"

void qemu_quit(unsigned char status) {
    const static unsigned char DEBUG_EXIT_PORT = 0xF4;
    out11(status, DEBUG_EXIT_PORT);
}
