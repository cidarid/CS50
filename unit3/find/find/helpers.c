// Helper functions

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/*int main(void) {
    int tests[6] = {1, 3, 89, 4, 8, 6};
    sort(tests, 6);
}*/

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
    }
    // TODO: implement a searching algorithm
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    bool unsorted = true;
    int first, second;
    while (unsorted)
    {
        for (int i = 0; i < n; i++)
        {
            if (values[i] < values[i - 1])
            {
                unsorted = true;
                first = values[i - 1];
                second = values[i];
                values [i - 1] = second;
                values[i] = first;
                //printf("%i should be larger than %i.", first, second);
            }
            else
            {
                unsorted = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("\nElement %i: %i", i, values[i]);
        }
    }
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
