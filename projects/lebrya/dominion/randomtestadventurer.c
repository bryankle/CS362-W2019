#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"
#include "test.h"

int main()
{
    enum players {player_1, player_2};
    char buffer[500];
    int number_of_players;
    int kingdom_cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int seed = 100;
    struct gameState game_state;

    // Generate number of random players (1 - 4)
    srand(time(NULL));
    number_of_players = (rand() % (MAX_PLAYERS - 1)) + 2;

    printf("Testing with %d players.\n", number_of_players);
    initializeGame(number_of_players, kingdom_cards, seed, &game_state);

    int handcount_0[number_of_players];
    int handcount_1[number_of_players];
    int i;
    int test_results[number_of_players];
    for (i = 0; i < number_of_players; i++)
    {
        int random_handCount = (rand() % MAX_HAND) + 1;
        // Initialize all players with random hand count
        game_state.handCount[i] = random_handCount;
        handcount_0[i] = game_state.handCount[i];

        // game_state.handCount[i] = 10;
        activate_adventurer(&game_state, i);
        handcount_1[i] = game_state.handCount[i];
        // printf("Player %d hand count: %d\n", i + 1, game_state.handCount[i]);
        // printf("Player %d deck count: %d\n", i + 1, game_state.deckCount[i]);
    }
    int j;
    int test_result;
    for (j = 0; j < number_of_players; j++)
    {
        memset(buffer, 0, 100 * sizeof(buffer[0]));
        int test_number = j + 1;
        int player_number = j + 1;
        // printf("Before: %d\nAfter: %d\n", handcount_0[j], handcount_1[j]);
        // int handcount_initial = handcount_0[j];
        // int handcount_final = handcount_1[j];
        // printf("%d should be 2 less than %d\n", handcount_0[j], handcount_1[j]);
        sprintf(buffer, "Test %d: Player %d original hand count should contain two less cards than updated hand count %d + 2 == %d", j + 1, j + 1, handcount_0[j], handcount_1[j]);
        printf("%s\n", buffer);
        // test_result = assert_true(handcount_0[j] + 2 == handcount_1[j]);
        // test_result = assert_true(handcount_0)
    }


    // int p1_handcount_0 = game_state.handCount[player_1];
    // int p1_discardcount_0 = game_state.discardCount[player_1];
    // int p2_handcount_0 = game_state.handCount[player_2];
    // int p2_discardcount_0 = game_state.discardCount[player_2];

    // activate_adventurer(&game_state, player_1);

    // int p1_handcount_1 = game_state.handCount[player_1];
    // int p2_handcount_1 = game_state.handCount[player_2];
    // int p1_discardcount_1 = game_state.discardCount[player_1];
    // int p2_discardcount_1 = game_state.discardCount[player_2];

    // printf("Card Test 1: Adventurer\n");

    // int test1 = assert_true(p1_handcount_0 == p1_handcount_1 - 2, "Test 1: Original hand count containsn two less cards than updated hand count.");
    // int test2 = assert_true(p2_handcount_0 == p2_handcount_1, "Test 2: Player 2 hand count should remain unchanged.");
    // int test3 = assert_true(p1_discardcount_0 == p1_discardcount_1, "Test 3: Player 1 discard count should remain unchanged.");
    // int test4 = assert_true(p2_discardcount_0 == p2_discardcount_1, "Test 4: Player 2 discard count should remain unchanged.");

    // int all_tests[] = {test1, test2, test3, test4};
    // check_all_tests(all_tests, 4);
    return 0;
}