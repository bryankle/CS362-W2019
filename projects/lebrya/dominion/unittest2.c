#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void assign_state_handCount(struct gameState *state, int player, int card_count)
{
    state->whoseTurn = player;
    state->handCount[player] = card_count;
}

// numHandCards
int main()
{
    srand(time(NULL));
    struct gameState G;
    int current_player = 0;
    int rand_int;
    int i = 0;
    for (i = 0; i < 20; i++) {
        rand_int = rand() % 100;
        assign_state_handCount(&G, current_player, rand_int);
        int player_handcount = numHandCards(&G);
        assert(player_handcount == rand_int);
    }
    // assign_state_handCount(&G,current_player, -1);
    // Test for negative values?
    printf("Unit test 2: All tests passing\n");
    return 0;
}