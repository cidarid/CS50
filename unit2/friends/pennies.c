#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        //If invalid amount of arguments return
        printf("Usage: ./pennies <days in month> <starting pennies>\n");
        return 1;
    }
    //Initializing variables
    double pennyCount;
    int dayCount = atoi(argv[1]);
    int tempPenniesPerDay = atoi(argv[2]);
    double penniesPerDay = (double)tempPenniesPerDay;
    double money;
    if (!(dayCount == 28 || dayCount == 29 || dayCount == 30 || dayCount == 31))
    {
        //Make sure dayCount is valid
        printf("Usage: ./pennies <days in month> <starting pennies>\n");
        return 1;
    }
    if (penniesPerDay < 1)
    {
        //Check that penniesPerDay is not negative
        printf("Usage: ./pennies <days in month> <starting pennies>\n");
        return 1;
    }
    pennyCount = penniesPerDay;
    for (int i = 0; i < dayCount; i++)
    {
        //Multiply the amount of pennies by 2 as long as the iteration is less than the days inputted
        pennyCount *= 2;
    }
    money = (pennyCount - penniesPerDay) / 100.0;
    printf("$%.2f\n", money);
}