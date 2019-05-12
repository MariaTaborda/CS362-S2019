CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: clean testme.c
	gcc -o testme testme.c $(CFLAGS)
	./testme
	gcov testme.c 

clean:
	rm testme 

all: clean testme
