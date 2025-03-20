TARGET = ascii85
TEST_TARGET = test

CXX = g++
CXXFLAGS = -Wall -g
TESTFLAGS = -lgtest -lgmock -pthread

SRC = main.cpp
OBJ = main.o

TEST_SRC = test.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

all: $(TARGET)

test: $(TEST_SRC)
	$(CXX) $(TEST_SRC) $(CXXFLAGS) -o $(TEST_TARGET) $(TESTFLAGS)

clean_test:
	rm -f $(TEST_TARGET)

clean:
	rm -f $(TARGET) $(OBJ)