all: frequency

frequency: trie.o frequency.o
		gcc -Wall -g -o frequency trie.o frequency.o
trie.o: trie.c trie.h
		gcc -Wall -g -fPIC -c trie.c
main.o: frequency.c trie.h
		gcc -Wall -g -fPIC -c frequency.c

.PHONY: clean all

clean:	
		rm -f *.o frequency