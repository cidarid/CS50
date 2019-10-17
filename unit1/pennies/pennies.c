#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Initializing variables
    double pennyCount;
    int dayCount = 0;
    double penniesPerDay;
    double money;
    do
    {
        //Get user input for days of the month
        dayCount = get_int("Days in month: ");
    }
    //Return if dayCount doesn't equal 28, 29, 30, or 31
    while (!(dayCount == 28 || dayCount == 29 || dayCount == 30 || dayCount == 31));
    do
    {
        //Get user input for pennies
        penniesPerDay = get_int("Pennies on first day: ");
    }
    //Return if penniesPerDay is negative
    while (penniesPerDay < 1);
    pennyCount = penniesPerDay;
    for (int i = 0; i < dayCount; i++)
    {
        //Multiply the amount of pennies by 2 as long as the iteration is less than the days inputted
        pennyCount *= 2;
    }
    money = (pennyCount - penniesPerDay) / 100.0;
    printf("$%.2f\n", money);
    //29 days 2 pennies should be 10737418.22\n
}