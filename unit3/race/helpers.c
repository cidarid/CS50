// Helper functions for the sort race

#include <cs50.h>
#include "helpers.h"
#include <stdio.h>

// Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    char *validFlags[4] = {"-a", "-b", "-r", "-s"};
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(str, validFlags[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

// Sorts array of n values using bubble sort
void bubble(int values[], int n)
{
    bool sorted = false;
    int sortedCount = 0;
    while (!sorted)
    {
        sortedCount = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
            }
            else
            {
                sortedCount++;
            }
        }
        if (sortedCount == n)
        {
            sorted = true;
        }
    }
    return;
}

// Sorts array of n values using selection sort
void selection(int values[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (values[j] < values[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = values[min_idx];
        values[min_idx] = values[i];
        values[i] = temp;
    }
    return;
}

// Sorts array of n values using insertion sort
void insertion(int values[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = values[i];
        j = i - 1;
        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j = j - 1;
        }
        values[j + 1] = key;
    }
}
