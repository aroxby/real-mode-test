FROM ubuntu:bionic

RUN apt-get update && apt-get install -y \
    build-essential \
    nasm \
    qemu-system-x86

ADD . /src
WORKDIR /src

RUN make && ndisasm boot.bin

CMD qemu-system-x86_64 \
    -drive file=boot.mbr \
    -nographic \
    -net none \
    -device isa-debug-exit,iobase=0xf4,iosize=0x01 || exit $(($?>>1))