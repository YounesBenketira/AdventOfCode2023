# Compiler
CC = gcc

# Directories
SRC_DIR = src
BUILD_DIR = build

PART1_DIR = $(SRC_DIR)/part_1
PART2_DIR = $(SRC_DIR)/part_2
BUILD_PART1 = $(BUILD_DIR)
BUILD_PART2 = $(BUILD_DIR)

# Source files
PART1_SRC = $(wildcard $(PART1_DIR)/*.c)
PART2_SRC = $(wildcard $(PART2_DIR)/*.c)

# Output binaries
PART1_OUT = $(BUILD_PART1)/part_1
PART2_OUT = $(BUILD_PART2)/part_2

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Default target
all: $(PART1_OUT) $(PART2_OUT)

# Build part_1 target
$(PART1_OUT): $(PART1_SRC) | $(BUILD_PART1)
	$(CC) $(CFLAGS) $(PART1_SRC) -o $(PART1_OUT)

# Build part_2 target
$(PART2_OUT): $(PART2_SRC) | $(BUILD_PART2)
	$(CC) $(CFLAGS) $(PART2_SRC) -o $(PART2_OUT)

# Ensure build directories exist
$(BUILD_PART1):
	mkdir -p $(BUILD_PART1)

$(BUILD_PART2):
	mkdir -p $(BUILD_PART2)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# PHONY targets
.PHONY: all clean

