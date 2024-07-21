# Directories
MSPGCC_ROOT_DIR = /home/vietduc/Documents/dev/tools/msp430-gcc
MSPGCC_BIN_DIR = $(MSPGCC_ROOT_DIR)/bin
MSPGCC_INCLUDE_DIR = $(MSPGCC_ROOT_DIR)/include
INCLUDE_DIRS = $(MSPGCC_INCLUDE_DIR)
LIB_DIRS = $(MSPGCC_INCLUDE_DIR)
BUILD_DIR = /home/vietduc/Documents/Blink
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
SOURCE_DIR = $(BUILD_DIR)/src
HEADERS_DIR = $(BUILD_DIR)/include

# Define directories and tools
TI_CSS_DIR = /home/vietduc/ti/ccs1271/ccs/ccs_base/DebugServer
DEBUG_BIN_DIR = $(TI_CSS_DIR)/bin
DEBUG_DRIVERS_DIR = $(TI_CSS_DIR)/drivers
DEBUG = LD_LIBRARY_PATH=$(DEBUG_DRIVERS_DIR) $(DEBUG_BIN_DIR)/mspdebug

# Toolchain
CC = $(MSPGCC_BIN_DIR)/msp430-elf-gcc
GDB = $(MSPGCC_BIN_DIR)/msp430-elf-gdb

# Target
TARGET = $(BIN_DIR)/blink

# Source files
SRCS = $(SOURCE_DIR)/blink.c \
	$(SOURCE_DIR)/gpio.c

# Object files
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Flags
MCU = msp430fr6989
WFLAGS = -Wall -Wextra -Werror -Wshadow
CFLAGS = -mmcu=$(MCU) $(WFLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -I,$(HEADERS_DIR)) -Og -g
LDFLAGS = -mmcu=$(MCU) $(addprefix -L,$(LIB_DIRS)) $(addprefix -L,$(HEADERS_DIR)) 

# Build
## Linking
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@

## Compiling
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@

## Debug
debug: $(TARGET)
	$(GDB) $(TARGET)

## Flash
flash: $(TARGET)
	$(DEBUG) tilib "prog $(TARGET)"

# Phony
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
