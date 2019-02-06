#ifndef _TEST_H
#define _TEST_H

#include <stdlib.h>
#include <stdio.h>

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

#endif