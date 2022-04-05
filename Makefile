all: signals 

signals: signals.o
	gcc -Wall -g signals.o -o signals
	
main.o: main.c
	gcc -Wall -g -c signals.c 

.PHONY: clean all

clean:
	rm -f *.o signals
