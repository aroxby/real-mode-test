org 0x7C00
use16

mov al, '*'
mov dx, 0x3F8
out dx, al

mov al, 0
out 0xf4, al

cli
haltloop:
hlt
jmp haltloop

times 510-($-$$) nop
dw 0AA55h