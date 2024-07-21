OBJECTS = blink.o

TI_CSS_DIR = /home/vietduc/ti/ccs1271/ccs/ccs_base/DebugServer
DEBUG_BIN_DIR = $(TI_CSS_DIR)/bin
DEBUG_DRIVERS_DIR = $(TI_CSS_DIR)/drivers
DEBUG = LD_LIBRARY_PATH=$(DEBUG_DRIVERS_DIR) $(DEBUG_BIN_DIR)/mspdebug
GCC_DIR = /home/vietduc/Documents/dev/tools/msp430-gcc/bin
SUPPORT_FILE_DIR = /home/vietduc/Documents/dev/tools/msp430-gcc/include

DEVICE = msp430fr6989
CC = $(GCC_DIR)/msp430-elf-gcc
GDB = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIR) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIR) -T $(SUPPORT_FILE_DIR)/$(DEVICE).ld

.PHONY: all debug flash clean

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECTS) -o $(DEVICE).out

debug: all
	$(GDB) $(DEVICE).out

flash:
	sudo $(DEBUG) tilib "prog $(DEVICE).out"

clean:
	rm -f $(OBJECTS) $(DEVICE).out

