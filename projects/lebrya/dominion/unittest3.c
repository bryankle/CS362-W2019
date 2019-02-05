#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void assign_state_whoseTurn(struct gameState *G, int player)
{
    G->whoseTurn = player;
}

// whoseTurn
int main()
{
    struct gameState G;
    int i;

    for (i = 0; i < 50; i++)
    {
        assign_state_whoseTurn(&G, i);
        int player = whoseTurn(&G);
        assert(player == i);
    }

    printf("Unit test 3: All tests passing\n");
    return 0;
}