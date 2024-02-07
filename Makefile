# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -g

# Define executable file
TARGET = kaleidoscope

# Define object files
OBJ = main.o lexer.o parser.o

# Default target
all: $(TARGET)

# Link the object files into a binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile the source files into object files
main.o: main.cpp lexer.h parser.h
	$(CXX) $(CXXFLAGS) -c main.cpp

lexer.o: lexer.cpp lexer.h
	$(CXX) $(CXXFLAGS) -c lexer.cpp

parser.o: parser.cpp parser.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)

# Specify phony targets
.PHONY: all clean