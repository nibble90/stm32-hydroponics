# Compilation variables
CC := arm-none-eabi-gcc
COMMON_CFLAGS := -mcpu=cortex-m3 -mthumb
DEBUG ?= 0
ifeq ($(DEBUG),1)
	CFLAGS := $(COMMON_CFLAGS) -g -Wall -Wconversion
else
	CFLAGS := $(COMMON_CFLAGS)
endif

# Linker options
LDFLAGS := -Wl,-Tmemory.ld -nostartfiles

# Source files
SRCS := $(wildcard *.c peripherals/*.c src/*.c)

# Object files
OBJS := $(foreach objectfile,$(notdir $(SRCS:.c=.o)),bin/$(objectfile))

# Targets
deploy:  main.bin
	st-flash --connect-under-reset write bin/main.bin 0x08000000

main.bin: main.elf
	arm-none-eabi-objcopy -O binary bin/main.elf bin/main.bin

main.elf: $(SRCS:.c=.o)
	$(CC) -o bin/main.elf $(OBJS) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -o bin/$(notdir $@) -c $(CFLAGS) $<

build: main.bin

clean:
	rm bin/*.o bin/*.elf bin/*.bin