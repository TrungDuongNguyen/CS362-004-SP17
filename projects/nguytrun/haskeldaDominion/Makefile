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

unittestresults.out: dominion.c rngs.o

	gcc -o unittest1 dominion.c unittest1.c rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o unittest2 dominion.c unittest2.c rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o unittest3 dominion.c unittest3.c rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o unittest4 dominion.c unittest4.c rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	gcc -o cardtest1 dominion.c cardtest1.c rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest2 dominion.c cardtest2.c rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest3 dominion.c cardtest3.c rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest4 dominion.c cardtest4.c rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomunittest.out: dominion.c rngs.o

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
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
