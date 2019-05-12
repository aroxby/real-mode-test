FROM ubuntu:bionic

RUN apt-get update && apt-get install -y \
    nasm \
    qemu-system-x86

ADD . /src
WORKDIR /src
RUN nasm main.asm -o boot.bin

RUN bash -c 'echo -e \\x55\\xAA | dd of=boot.bin bs=2 count=1 seek=255 2>&1'

CMD qemu-system-x86_64 \
    -drive file=boot.bin \
    -nographic \
    -net none \
    -device isa-debug-exit,iobase=0xf4,iosize=0x01 || exit $(($?>>1))