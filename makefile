# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/bst

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rules to compile source files into object files
$(BUILD_DIR)/decipherFile.o: $(SRC_DIR)/decipherFile.c $(INC_DIR)/decipherFile.h $(INC_DIR)/graph.h $(INC_DIR)/types.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/dfs.o: $(SRC_DIR)/dfs.c $(INC_DIR)/dfs.h $(INC_DIR)/types.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/graph.o: $(SRC_DIR)/graph.c $(INC_DIR)/graph.h $(INC_DIR)/types.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/decipherFile.h $(INC_DIR)/dfs.h $(INC_DIR)/types.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

# Run the program with the data file
run: $(TARGET)
	@$(TARGET)

# Phony targets
.PHONY: all clean run