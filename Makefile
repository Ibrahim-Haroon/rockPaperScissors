CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.cpp)

OBJ = $(SRC:.cpp=.o)

EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXECUTABLE)


