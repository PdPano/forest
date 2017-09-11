SRC =  main.cpp

OBJECTS := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC)))

PROGRAM = avl_tree.x

CC = gcc
CFLAGS = -g -Wall -Wextra
CXX = g++
CXXFLAGS = $(CFLAGS)

main: $(OBJECTS) avl_tree.hpp makefile
	$(CXX) $(CFLAGS) $(OBJECTS) -o $(PROGRAM)

%.o: %.cpp makefile
	$(CXX) -c -o $@ $<

clean:
	@rm -f $(OBJECTS) $(PROGRAM)
