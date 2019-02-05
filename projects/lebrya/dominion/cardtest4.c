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
    game_state.hand[player_1][0] = great_hall;

    printf("Card Test 4: Great Hall\n");

    int p1_handcount_0 = game_state.handCount[player_1];
    int num_action_0 = game_state.numActions;
    activate_great_hall(&game_state, player_1, 0);

    int p1_handcount_1 = game_state.handCount[player_1];
    int num_action_1 = game_state.numActions;

    int test1 = assert_true(p1_handcount_0 == p1_handcount_1, "Test 1: Player 1 hand count should remain unchanged after drawing and discarding a card.");
    int test2 = assert_true(num_action_0 + 1 == num_action_1, "Test 2: Number of actions should increase by one.");

    int all_tests[] = {test1, test2};
    check_all_tests(all_tests, 2);

    return 1;
}