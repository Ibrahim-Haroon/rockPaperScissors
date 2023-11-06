CXX = g++
CXXFLAGS = -std=c++11

SRCDIR = src
TESTDIR = tests

all: main unittest

main: $(SRCDIR)/main.cpp $(SRCDIR)/RPS.cpp
	$(CXX) $(CXXFLAGS) -o main $(SRCDIR)/main.cpp $(SRCDIR)/RPS.cpp

unittest: $(TESTDIR)/tests_rps.cpp $(SRCDIR)/RPS.cpp
	$(CXX) $(CXXFLAGS) -o unittest -I$(SRCDIR) $(TESTDIR)/tests_rps.cpp $(SRCDIR)/RPS.cpp

.PHONY: clean

clean:
	rm -f main unittest
