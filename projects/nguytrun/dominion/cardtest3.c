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
	printf("Testing Adventurer\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
	
	int numActions,handCount;
	struct gameState gS;
	initializeGame(2, k, 789, &gS);
	
	int curplayer = 0;
	gS.whoseTurn = curplayer;

	numActions = gS.numActions; 
	handCount = gS.handCount[curplayer]; 

	cardEffect(adventurer,0,0,0,&gS,handCount-1);
	
	my_assert(gS.numActions == numActions, "numActions should have been same");
	my_assert(gS.handCount[curplayer] == handCount+2, "handCount should hve increased");
	
	printf("Card Test 3 Passed\n");
	return 0;
}
