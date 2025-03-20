TARGET = ascii85
CXX = g++
CXXFLAGS = -Wall -g

SRC = main.cpp
OBJ = main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)