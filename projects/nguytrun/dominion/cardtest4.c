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
	printf("Testing GreatHall\n");
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

	cardEffect(great_hall,1,0,0,&gS,handCount-1);
	
	my_assert(gS.deckCount[curplayer] == deckCount - 1, "deckCount should be down by 3");
	my_assert(gS.numActions == numActions+1, "numActions should have been same");
	my_assert(gS.handCount[curplayer] == handCount, "handCount should hve decreased");
	
	printf("Card Test 4 Passed\n");
	return 0;
}
