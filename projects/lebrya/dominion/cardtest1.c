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

    activate_adventurer(&game_state, player_1);

    int p1_handcount_1 = game_state.handCount[player_1];
    int p2_handcount_1 = game_state.handCount[player_2];
    int p1_discardcount_1 = game_state.discardCount[player_1];

    printf("Card Test 1: Adventurer\n");


    int test1 = assert_true(p1_handcount_0 == p1_handcount_1 - 2, "Test 1: Original hand count containsn two less cards than updated hand count.");
    int test2 = assert_true(p2_handcount_0 == p2_handcount_1, "Test 2: Player 2 hand count remains unchanged.");

    int all_tests[] = {test1, test2};

    check_all_tests(all_tests, 2);
    return 0;
}