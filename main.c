__asm__("\
    .code16\n\
    \n\
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
