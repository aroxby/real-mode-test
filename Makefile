CFLAGS=-O1 -m16
LDFLAGS=-e boot -m elf_i386
OBJCOPYSECTS=.text
OBJCOPYFLAGS=$(foreach s, $(OBJCOPYSECTS), -j $s) -O binary

SRC_DIR=.
SRCS=$(shell find $(SRC_DIR) -name '*.c')
OBJS=$(subst .c,.o,$(SRCS))
TARGET_NAME=boot
ELF_TARGET=$(TARGET_NAME).elf
TARGET=$(TARGET_NAME).bin
DISK=$(TARGET_NAME).mbr

OBJCOPY=objcopy

.PHONY: default all disk tidy clean

default: all

all: disk

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF_TARGET): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

$(TARGET): $(ELF_TARGET)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(DISK): $(TARGET)
	cp $< $@
	bash -c 'echo -e \\x55\\xAA' | dd of=$@ bs=2 count=1 seek=255 2>&1

disk: $(DISK)

tidy:
	rm -f $(OBJS) $(ELF_TARGET)

clean: tidy
	rm -rf $(TARGET) $(DISK)
