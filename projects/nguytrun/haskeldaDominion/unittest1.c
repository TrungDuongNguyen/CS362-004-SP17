//buying a Card Test
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	printf("BuyCard Test\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	struct gameState gS;
	initializeGame(2, k, 789, &gS);
	
	int i;
	int exist = 0;

	buyCard(village,&gS);

	for (i = 0; i < gS.deckCount[0]; i++)
	{
		if (gS.deck[0][i] == village)
		{
			exist = 1;
			break;
		}
	}
	
	for (i = 0; i < gS.handCount[0]; i++)
    {
      if (gS.hand[0][i] == village) 
		{
			exist = 1;
			break;
		}
    }

    for (i = 0; i < gS.discardCount[0]; i++)
    {
      if (gS.discard[0][i] == village)
		{
			exist = 1;
			break;
		}
    }
	
	for (i = 0; i < gS.deckCount[0]; i++)
	{
		if (gS.deck[1][i] == village)
		{
			exist = 1;
			break;
		}
	}
	
	for (i = 0; i < gS.handCount[0]; i++)
    {
      if (gS.hand[1][i] == village) 
		{
			exist = 1;
			break;
		}
    }

    for (i = 0; i < gS.discardCount[0]; i++)
    {
      if (gS.discard[1][i] == village)
		{
			exist = 1;
			break;
		}
    }
	
	if (!exist)
	{
		printf("card not here\n");
	}
	else
		printf("Card was Added\n");
		printf("Unit Test 1 Successful\n");
	return 0;

}