CXX = /opt/homebrew/opt/llvm/bin/clang++
CXXFLAGS = -std=c++11 -g

# Automatically find all .cpp files and convert them to .o files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = main

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)