//cardcount test after ending turns
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	printf("CardCount Test\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	struct gameState gS;
	initializeGame(2, k, 456, &gS);
	

	endTurn(&gS);

	endTurn(&gS);

	printf("deckcount: %i\n", gS.deckCount[0]);
    printf("discardcount: %i\n", gS.discardCount[0]);
    printf("handcount: %i\n", gS.handCount[0]);
	
	printf("deckcount: %i\n", gS.deckCount[1]);
    printf("discardcount: %i\n", gS.discardCount[1]);
    printf("handcount: %i\n", gS.handCount[1]);
	
	if (gS.deckCount[0] == gS.handCount[1])
	{
		printf("first");
		if (gS.discardCount[0]==gS.discardCount[1])
		{
			if (gS.handCount[0]==gS.deckCount[1])
			{
				printf("everything is good\n");
				printf("Unit Test 3 Succesful\n");
			}
		}
	}

	return 0;
}