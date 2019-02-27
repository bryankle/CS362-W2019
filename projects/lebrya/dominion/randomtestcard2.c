#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test.h"

int main()
{
    char buffer[100];
    struct gameState game_state;
    enum players {player_1, player_2};
    int number_of_players;
    int kingdom_cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int seed = 100;
    int i;
    int k;
    srand(time(NULL));
    number_of_players = (rand() % (MAX_PLAYERS - 1)) + 2;

    initializeGame(number_of_players, kingdom_cards, seed, &game_state);
    char handcounts_init[number_of_players];
    char handcounts_final[number_of_players];

    for (i = 0; i < number_of_players; i++)
    {
        int random_handCount = (rand() % MAX_HAND) + 1;
        game_state.handCount[i] = random_handCount;
        handcounts_init[i] = game_state.handCount[i];
        activate_adventurer(&game_state, i);
        handcounts_final[i] = game_state.handCount[i];
    }

    for (k = 0; k < number_of_players; k++)
    {
        printf("%d and %d\n", handcounts_init[k], handcounts_final[k]);
        memset(buffer, 0, 100 * sizeof(buffer[0]));
        sprintf(buffer, "Test %d: Player %d hand count should increase by 3", k + 1, k + 1);
        printf("%s\n", buffer);
    }

    return 0;
}