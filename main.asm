.code16

movb $'*', %al
movw $0x3F8,%dx
outb %al,%dx

movb $0,%al
outb %al, $0xf4

cli
haltloop:
hlt
jmp haltloop
