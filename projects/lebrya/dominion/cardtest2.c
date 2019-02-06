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

    int p1_cardcount_0 = game_state.handCount[player_1];
    int p1_deckcount_0 = game_state.deckCount[player_1];
    int p2_cardcount_0 = game_state.handCount[player_2];
    int p2_deckcount_0 = game_state.deckCount[player_2];
    activate_smithy(&game_state, player_1);

    int p1_cardcount_1 = game_state.handCount[player_1];
    int p1_deckcount_1 = game_state.deckCount[player_1];
    int p2_cardcount_1 = game_state.handCount[player_2];
    int p2_deckcount_1 = game_state.deckCount[player_2];

    printf("Card Test 2: Smithy\n");
    int test1 = assert_true(p1_cardcount_0 + 3 - 1 == p1_cardcount_1, "Test 1: Player 1 card count should increase by 3 after Smithy.");
    int test2 = assert_true(p1_deckcount_0 - 3 == p1_deckcount_1, "Test 2: Player 1 deck count should contain 3 less cards.");
    int test3 = assert_true(p2_cardcount_0 == p2_cardcount_1, "Test 3: Player 2 card count should be unaltered.");
    int test4 = assert_true(p2_deckcount_0 == p2_deckcount_1, "Test 4: Player 2 deck count should be unaltered.");
    int all_tests[] = {test1, test2, test3, test4};
    check_all_tests(all_tests, 4);
    return 0;
}