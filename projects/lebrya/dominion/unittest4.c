#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test.h"

#define CARD_SIZE 27

int main()
{
    int curse = 0;
    int estate = 2;
    int duchy = 5;
    int province = 8;
    int copper = 0;
    int silver = 3;
    int gold = 6;
    int adventurer = 6;
    int council_room = 5;
    int feast = 4;
    int gardens = 4;
    int mine = 5;
    int remodel = 4;
    int smithy = 4;
    int village = 3;
    int baron = 4;
    int great_hall = 3;
    int minion = 5;
    int steward = 3;
    int tribute = 5;
    int ambassador = 3;
    int cutpurse = 4;
    int embargo = 2;
    int outpost = 5;
    int salvager = 4;
    int sea_hag = 4;
    int treasure_map = 4;

    int cards[CARD_SIZE] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room,
    feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute,
    ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

    int i;
    printf("Unit test 4: getCost");
    for (i = 0; i < CARD_SIZE; i++)
    {
        int cost = getCost(i);
        assert_true(cost == cards[i], "Card cost correctly assigned");
    }

    printf("Unit test 4: All tests passing\n");
    return 0;
}