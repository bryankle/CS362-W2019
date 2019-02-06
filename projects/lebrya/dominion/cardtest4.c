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
    struct gameState game_state;
    enum players {player_1, player_2};
    int num_players = 2;
    int kingdom_cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int seed = 100;

    initializeGame(num_players, kingdom_cards, seed, &game_state);
    game_state.hand[player_1][0] = great_hall;

    printf("Card Test 4: Great Hall\n");

    int p1_handcount_0 = game_state.handCount[player_1];
    int num_action_0 = game_state.numActions;
    int p2_handcount_0 = game_state.handCount[player_2];
    activate_great_hall(&game_state, player_1, 0);

    int p1_handcount_1 = game_state.handCount[player_1];
    int num_action_1 = game_state.numActions;
    int p2_handcount_1 = game_state.handCount[player_2];

    int test1 = assert_true(p1_handcount_0 == p1_handcount_1, "Test 1: Player 1 hand count should remain unchanged after drawing and discarding a card.");
    int test2 = assert_true(num_action_0 + 1 == num_action_1, "Test 2: Number of actions should increase by one.");
    int test3 = assert_true(p2_handcount_0 == p2_handcount_1, "Test 3: Player 2 hand count should remain unaltered.");

    int all_tests[] = {test1, test2, test3};
    check_all_tests(all_tests, 3);

    return 0;
}