# Compiler
CC = gcc

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Target executable
TARGET = my_program

# Compiler flags
CFLAGS = -I$(INC_DIR) -Wall -g

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
