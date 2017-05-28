#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>




int main() {
	printf("Testing Smithy\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
	
	int numActions,handCount,deckCount;
	struct gameState gS;
	int deckcountBug,numActionBug,handCountBug = 0;
	
	for (int i = 0; i < 2000; i++)
	{
		int numPlayers = rand()%4;
		int gameSeed = rand()%5000;
		initializeGame(numPlayers, k, gameSeed, &gS);
	
	
		int curplayer = 0;
		gS.whoseTurn = curplayer;

		deckCount = gS.deckCount[curplayer];
		numActions = gS.numActions; 
		handCount = gS.handCount[curplayer];
		
		cardEffect(smithy,0,0,0,&gS,handCount-1);
		//pSmithy(&gS,curplayer);

		if(gS.deckCount[curplayer] != deckCount - 3)
		{
			deckcountBug +=1;
		}
		if(gS.numActions != numActions )
		{
			numActionBug +=1;
		}
		if(gS.handCount[curplayer] != handCount+2)
		{
			handCountBug +=1;
		}
			
	}

	printf("Amount of deckcount bugs %d\n",deckcountBug);
	printf("Amount of numActionBug bugs %d\n",numActionBug);
	printf("Amount of handCountBug bugs %d\n",handCountBug);
	return 0;
}