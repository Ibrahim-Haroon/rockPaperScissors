CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCDIR = src
SOURCES = $(SRCDIR)/RPS.cpp $(SRCDIR)/main.cpp $(SRCDIR)/tests_rps.cpp
HEADERS = $(SRCDIR)/RPS.h $(SRCDIR)/tests_rps.h

main: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o main

tests: $(SRCDIR)/tests_rps.cpp $(SRCDIR)/RPS.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/tests_rps.cpp $(SRCDIR)/RPS.cpp -o tests

.PHONY: clean

clean:
	rm -f main tests


