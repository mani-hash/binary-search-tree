# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iinclude/actions -g

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/actions/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Final executable
TARGET = $(BUILD_DIR)/bst

# Default rule
all: $(TARGET)

# Create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/actions

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	@$(TARGET)

.PHONY: all clean
