CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = unit

# Source files
SOURCES = LRUCache.cpp main.cpp

# Build rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

test: all
	./$(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
