#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Initialzing variables
    bool isISBN = false;
    long long isbn = get_long("ISBN: ");
    int modifiedISBN = 0;
    int tenth = isbn % 10;
    for (int i = 10; i > 0; i--)
    {
        //Checks that code fits the formula
        modifiedISBN += (isbn % 10) * i;
        isbn /= 10;
    }
    //Checks that it is divisible by 0
    isISBN = modifiedISBN % 11 == 0;
    //Sending whether its true or false
    if (isISBN)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}