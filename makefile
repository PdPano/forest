SRC = avl_tree.c main.c

OBJECTS := $(patsubst %.c,%.o, $(filter %.c,$(SRC)))

PROGRAM = avl_tree.x

CC = gcc
CFLAGS = -g -Wall -Wextra

main: $(OBJECTS) makefile
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROGRAM)

%.o: %.c makefile
	$(COMPILE.c) $(DEPFLAGS) -o $@ $<

clean:
	@rm -f $(OBJECTS) $(PROGRAM)
