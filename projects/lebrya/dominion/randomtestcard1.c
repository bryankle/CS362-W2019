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
    srand(time(NULL));
    number_of_players = 4;//(rand() % (MAX_PLAYERS - 1)) + 2;

    initializeGame(number_of_players, kingdom_cards, seed, &game_state);

    printf("Card Test 3: Village\n");

    int i;
    // Generate random player in range of number_of_players
    int player = (rand() % (number_of_players));

    printf("Number of players: %d\n", number_of_players);
    printf("Player selected: %d\n", player);

    int rand_player_handcount_0 = game_state.handCount[player];
    int num_actions_0 = game_state.numActions;

    // Set first card to village
    game_state.hand[player][0] = village;

    activate_village(&game_state, player, 0);

    int rand_player_handcount_1 = game_state.handCount[player];
    int num_actions_1 = game_state.numActions;

    memset(buffer, 0, 100 * sizeof(buffer[0]));
    sprintf(buffer, "Test 1: Player %d handcount should remain the same after drawing a card and discarding Village.", player + 1);
    int test1 = assert_true(rand_player_handcount_0 == rand_player_handcount_1, buffer);
    int test2 = assert_true(num_actions_0 == num_actions_1 - 2, "Test 2: Number of actions should be increased by 2.");

    int all_tests[] = {test1, test2};

    check_all_tests(&all_tests, 2);

    return 0;

}