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

INLINE void hlt();
INLINE void cli();
INLINE void out11(unsigned char value, unsigned char port);
INLINE void out12(unsigned char value, unsigned short port);

void main() {
    out12('*', 0x3F8);
    out11(0, 0xF4);
    cli();
    while(1) {
        hlt();
    }
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