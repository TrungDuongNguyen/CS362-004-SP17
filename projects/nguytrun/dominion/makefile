CFLAGS = -Wall -fpic -coverage -lm -std=c99


rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomunittest.out: dominion.c


	
	gcc -o randomtestadventure dominion.c randomtestadventure.c rngs.o $(CFLAGS)
	randomtestadventure >> randomunittest.out
	gcov randomtestadventure.c >> randomunittest.out
	
	gcc -o randomcardtest1 dominion.c randomcardtest1.c rngs.o $(CFLAGS)
	randomcardtest1 >> randomunittest.out
	gcov randomcardtest1.c >> randomunittest.out
	
	gcc -o randomcardtest2 dominion.c randomcardtest2.c rngs.o $(CFLAGS)
	randomcardtest2 >> randomunittest.out
	gcov randomcardtest2.c >> randomunittest.out
	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o randomunittest.out playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
