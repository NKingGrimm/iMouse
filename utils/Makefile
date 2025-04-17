# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I../include

# Paths
SRC_DIR = ../src
INCLUDE_DIR = ../include
OUTPUT_DIR = ../output

# Files
SRCS = $(SRC_DIR)/iMouse.cpp
OBJS = $(OUTPUT_DIR)/iMouse.o
TARGET = $(OUTPUT_DIR)/iMouseApp

# Default target
all: $(TARGET)

# Make sure output folder exists
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Build target
$(TARGET): $(OUTPUT_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source into output/ directory
$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean everything
clean:
	rm -rf $(OUTPUT_DIR)
