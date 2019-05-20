CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

#testDrawCard: testDrawCard.c dominion.o rngs.o
#	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
#	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

#testBuyCard: testDrawCard.c dominion.o rngs.o
#	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#testAll: dominion.o testSuite.c
#	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

#runtests: testDrawCard 
#	./testDrawCard &> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out


randomtest: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)


randomtestresults: clean randomtest
	echo "Results of running randomtest1:" >>randomtestresults.out
	./randomtestcard1 >> randomtestresults.out
	echo "Coverage after randomtestcard1" >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	echo "Results of running randomtest2:" >>randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	echo "Coverage after randomtestcard2" >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	echo "Results of running randomtestadventurer:" >>randomtestresults.out
	./randomtestadventurer >> randomtestresults.out
	echo "Coverage after randomtestadventurer" >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	gcov -f -b dominion.c >>randomtestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

#unittest1: unittest1.c dominion.o rngs.o
#	gcc - o unittest1 unittest1.c -g dominion.o rngs.o

all: playdom player randomtest

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
