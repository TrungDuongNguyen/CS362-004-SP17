//supply coutn test
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	printf("SupplyCount Test\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	struct gameState gS;
	
	gS.supplyCount[smithy] = 4;
	gS.supplyCount[mine] = 8;
	gS.supplyCount[tribute] = 1;
	
	if (supplyCount(mine,&gS) == 8)
	{
		printf("Expected mine to have correct value\n");
		if(supplyCount(tribute,&gS) == 1)
		{
			printf("Expected tribute to have correct value\n");
			if(supplyCount(smithy,&gS) == 4)
			{
				printf("expected smithy to have correct value\n");
				printf("Unit Test 4 succesful\n");
			}
		}
	}
	return 0;
}	