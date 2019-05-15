/*
This instruction (while making the code more readable) is not needed if we are careful.
I was tempted to leave it in for clarity but this projects intention to achieve full parity
with hand written assembly.  I leave it here for reference.
asm("jmp main");
*/

/*
This is not strictly needed.
The GCC will normally choose to inline our simple functions anyway.
A simple `inline` will prevent the compilier from generating
full versions of the function (as well as inlining).
The "always_inline" should cause a warning to be raised if a function
is ever not inlined.
*/
#define INLINE __attribute__((always_inline)) inline

INLINE void serial_write(char ch);
INLINE void stop();
INLINE void qemu_quit(unsigned char status);
INLINE void out11(unsigned char value, unsigned char port);
INLINE void out12(unsigned char value, unsigned short port);
INLINE void hlt();
INLINE void cli();

void boot() {
    serial_write('*');
    stop();
}

INLINE void serial_write(char ch) {
    const static unsigned short COM1_PORT = 0x3F8;
    out12(ch, COM1_PORT);
}

INLINE void stop() {
    qemu_quit(0);
    cli();
    while(1) {
        hlt();
    }
}

INLINE void qemu_quit(unsigned char status) {
    const static unsigned char DEBUG_EXIT_PORT = 0xF4;
    out11(status, DEBUG_EXIT_PORT);
}

INLINE void cli() {
    asm("cli");
}

INLINE void hlt() {
    asm("hlt");
}

INLINE void out11(unsigned char value, unsigned char port) {
    asm("mov %0, %%al":: "i"(value));
    asm("out %%al, %0": : "i"(port));
}

INLINE void out12(unsigned char value, unsigned short port) {
    asm("mov %0, %%al": : "i"(value));
    asm("mov %0, %%dx": : "i"(port));
    asm("out %al, %dx");
}
