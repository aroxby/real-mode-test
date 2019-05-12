__asm__("\
    .code16\n\
    \n\
    movb $'*', %al\n\
    movw $0x3F8,%dx\n\
    outb %al,%dx\n\
    \n\
    movb $0,%al\n\
    outb %al, $0xf4\n\
    \n\
    cli\n\
    haltloop:\n\
    hlt\n\
    jmp haltloop\n\
");
