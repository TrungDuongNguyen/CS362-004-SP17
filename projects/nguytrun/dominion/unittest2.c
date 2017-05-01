//drawcard tests
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	printf("DrawCard Test\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	struct gameState gS;
	initializeGame(2, k, 123, &gS);
	

	int deckcardcounter = 0;
	int handcardcounter = 0;
	int discardcounter = 0;
	int curplayer = 0;
	gS.whoseTurn = curplayer;
	drawCard(curplayer,gS);


	
	deckcardcounter = gS.deckCount[curplayer];
	handcardcounter = gS.handCount[curplayer];
	discardcounter = gS.discardCount[curplayer];
	
	if (deckcardcounter == 4)
	{
		printf("4 cards in deck\n");
		if (discardcounter == 0)
		{
			printf("no cards in discard\n");
			if (handcardcounter == 6)
			{
				printf("got all 6 cards in hand\n");
				printf("Unit Test 2 Successful\n");
			}
		}
	}
	return 0;

}