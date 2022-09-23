CC=gcc
CFLAGS= -std=c11
LDLIBS=-lm

all: writte_node.o dictionary.o

writte_node.o: writte_node.c
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

dictionary.o: writte_node.o dictionary.c
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

clean:
	rm -rf *.o