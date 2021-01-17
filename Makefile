CC=gcc
OBJECTS_MAIN=subFrequency.o trie.o main.o
FLAGS= -Wall -g
PROGRAMS=frequency

all: $(PROGRAMS)
frequency: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) -lm
main.o: main.c
	$(CC) $(FLAGS) -c main.c
subFrequency.o: subFrequency.c subFrequency.h
	$(CC) $(FLAGS) -c subFrequency.c
trie.o: trie.c trie.h subFrequency.h 
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all

clean:
	rm -f *.o $(PROGRAMS)
