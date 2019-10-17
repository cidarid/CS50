#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define size_a(x) \
    (sizeof(x) / sizeof(x[0]))

int main(void)
{
    int coinCount = 0;
    int money = 0;
    double moneyValues[] = {25, 10, 5, 1};
    do
    {
        //If the input is negative, return here
        money = round(100 * get_float("Change owed: "));
    }
    while (money < 0);
    for (int i = 0; i < size_a(moneyValues); i++)
    {
        //Go through all items in the list of the money values
        while (money >= moneyValues[i])
        {
            //While the amount of money remaining is larger than or equal to the money given, repeat
            coinCount++;
            money -= moneyValues[i];
        }
    }
    printf("%i\n", coinCount);
}
