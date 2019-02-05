#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int assert_true(int a, char* str)
{
    if (a)
    {
        printf("%s\n", str);
        return 1;
    }
    printf("Assertion failed: %s\n", str);
    return 0;
}

int check_all_tests(int* tests, int num_tests)
{
    int i;
    int failure_count = 0;
    for (i = 0; i < num_tests; i++)
    {
        if (tests[i] == 0)
        {
            failure_count++;
            printf("Assertion failed - Test %d.\n", i + 1);
        }
    }
    if (failure_count > 0)
    {
        if (failure_count == 0)
            printf("%d test has failed.\n", failure_count);
        else printf("%d tests have failed.\n", failure_count);
        return 0;
    }
    else
    {
        printf("All tests passing.\n");
        return 1;
    }
}

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
    activate_smithy(&game_state, player_1);

    int p1_cardcount_1 = game_state.handCount[player_1];
    int p1_deckcount_1 = game_state.deckCount[player_1];

    printf("Card Test 2: Smithy\n");
    int test1 = assert_true(p1_cardcount_0 + 3 - 1 == p1_cardcount_1, "Test 1: Player 1 card count should increase by 3 after Smithy.");
    int test2 = assert_true(p1_deckcount_0 - 3 == p1_deckcount_1, "Test 2: Player 1 deck count should contain 3 less cards.");
    int all_tests[] = {test1, test2};
    check_all_tests(all_tests, 2);
    return 0;
}