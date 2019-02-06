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
    enum players {player_1, player_2};
    int number_of_players = 2;
    int kingdom_cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int seed = 100;
    struct gameState game_state;
    initializeGame(number_of_players, kingdom_cards, seed, &game_state);

    int p1_handcount_0 = game_state.handCount[player_1];
    int p1_discardcount_0 = game_state.discardCount[player_1];
    int p2_handcount_0 = game_state.handCount[player_2];
    int p2_discardcount_0 = game_state.discardCount[player_2];

    activate_adventurer(&game_state, player_1);

    int p1_handcount_1 = game_state.handCount[player_1];
    int p2_handcount_1 = game_state.handCount[player_2];
    int p1_discardcount_1 = game_state.discardCount[player_1];
    int p2_discardcount_1 = game_state.discardCount[player_2];

    printf("Card Test 1: Adventurer\n");

    int test1 = assert_true(p1_handcount_0 == p1_handcount_1 - 2, "Test 1: Original hand count containsn two less cards than updated hand count.");
    int test2 = assert_true(p2_handcount_0 == p2_handcount_1, "Test 2: Player 2 hand count should remain unchanged.");
    int test3 = assert_true(p1_discardcount_0 == p1_discardcount_1, "Test 3: Player 1 discard count should remain unchanged.");
    int test4 = assert_true(p2_discardcount_0 == p2_discardcount_1, "Test 4: Player 2 discard count should remain unchanged.");

    int all_tests[] = {test1, test2, test3, test4};
    check_all_tests(all_tests, 4);
    return 0;
}