#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>






int main() {
	printf("Testing Village\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
	
	int numActions,handCount,deckCount;
	struct gameState gS;
	int deckcountBug,numActionBug,handCountBug = 0;
	
	for (int i = 0; i < 2000; i++)
	{
		int numPlayers = rand()%4;
		int gameSeed = rand()%2000;
		initializeGame(numPlayers, k, gameSeed, &gS);
	
	
		int curplayer = 0;
		gS.whoseTurn = curplayer;

		deckCount = gS.deckCount[curplayer];
		numActions = gS.numActions; 
		handCount = gS.handCount[curplayer];

		//cardEffect(smithy,0,0,0,&gS,handCount-1);
		pVillage(&gS,curplayer);
		

		if(gS.deckCount[curplayer] != deckCount - 1)
		{
			deckcountBug +=1;
		}

		if(gS.handCount[curplayer] != handCount)
		{
			handCountBug +=1;
		}
		int handposcov = rand()%20;
		int choices1 = rand()%3;
		int choices2 = rand()%3;
		int choices3 = rand()%3;
		shuffle(curplayer,&gS);
		playCard(handposcov,choices1,choices2,choices3,&gS);
		

	}

	printf("Amount of deckcount bugs %d\n",deckcountBug);
	printf("Amount of numActionBug bugs %d\n",numActionBug);
	printf("Amount of handCountBug bugs %d\n",handCountBug);
	return 0;
}