# Target executable
TARGET = datastr

# Source files	
SRCS = main.cpp

# Compiler
CXX = g++

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CXX) $^ -o $(TARGET)

# Clean build files
clean:
	rm $(TARGET)
