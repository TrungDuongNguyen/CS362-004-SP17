#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int my_assert(int test, char* msg)
{
	if (!test) {
		printf ("ASSERT HAS FAILED: %s\n", msg);
		exit(-1);
	}
	return 0;
}

int main() {
	printf("Testing SMithy\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
	
	int deckCount,numActions,handCount;
	struct gameState gS;
	initializeGame(2, k, 789, &gS);
	
	int curplayer = 0;
	gS.whoseTurn = curplayer;
	deckCount = gS.deckCount[curplayer];
	numActions = gS.numActions; 
	handCount = gS.handCount[curplayer]; 

	cardEffect(smithy,0,0,0,&gS,handCount-1);
	
	my_assert(gS.deckCount[curplayer] == deckCount - 3, "deckCount should be down by 3");
	my_assert(gS.numActions == numActions, "numActions should have been same");
	my_assert(gS.handCount[curplayer] == handCount+2, "handCount should hve increased");
	
	printf("Card Test 2 Passed\n");
	return 0;
}
