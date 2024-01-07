# Makefile for CMake project

# Specify the compiler
CC := g++

# Specify the source and build directories
SRC_DIR := src
BUILD_DIR := build

# Specify the CMake build directory
CMAKE_BUILD_DIR := $(BUILD_DIR)

# Specify the name of the executable
TARGET := tamagochi

# CMake command
CMAKE := cmake

# Flags for the compiler
CFLAGS := -std=c++11 -Wall

# Default target
all: cmake

# Create build directory and run CMake
cmake:
	@mkdir -p $(CMAKE_BUILD_DIR)
	@cd $(CMAKE_BUILD_DIR) && $(CMAKE) $(CURDIR)

# Build the executable
build: cmake
	@$(MAKE) -C $(CMAKE_BUILD_DIR)

# Run the executable
run: build
	@$(CMAKE_BUILD_DIR)/$(TARGET)

# Clean the build directory
clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all cmake build run clean

