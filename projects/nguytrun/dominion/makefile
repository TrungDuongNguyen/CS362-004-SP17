CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

unittestresults.out: unittest1.c dominion.c

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
	
	
clean:
	rm unittestresults.out

cleanall:
	rm unittestresults.out unittest1  *.gcda *.gcno *.gcov
