/*
This instruction (while making the code more readable) is not needed if we are careful.
I was tempted to leave it in for clarity but this projects intention to achieve full parity
with hand written assembly.  I leave it here for reference.
asm("jmp main");
*/

void main() {
    asm("\
        mov $'*', %al\n\
        mov $0x3F8, %dx\n\
        out %al, %dx\n\
        \n\
        mov $0, %al\n\
        out %al, $0xf4\n\
        \n\
        cli\n\
        haltloop:\n\
        hlt\n\
        jmp haltloop\n\
    ");
}
