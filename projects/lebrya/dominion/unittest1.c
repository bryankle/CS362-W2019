#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    int* kingdom_cards_collection = kingdomCards(k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7],k[8],k[9]);
    
    int i;
    for (i = 0; i < 10; i++)
    {
        assert(k[i] == kingdom_cards_collection[i]);
    }
    printf("Unit test 1: All tests passing\n");
    return 0;
}