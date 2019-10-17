#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

long long length(long long x)
{
    long long exponent;
    int count = 0;
    while (x != 0)
    {
        // n = n/10
        x /= 10;
        ++count;
    }
    return count;
}

int main(void)
{
    long long number = get_long("Credit card number: ");
    long long originalNumber = number;
    long long storer = 0;
    long long changer = 0;  //Debug
    long long _length = length(number);
    int oddTemp = 0;
    for (int i = 0; i <= 16; i++)
    {
        if (i % 2 != 0)
        {
            //If position of number is odd
            oddTemp = (number % 10) * 2;
            while (oddTemp > 0)
            {
                storer += oddTemp % 10;
                oddTemp /= 10;
            }
        }
        else if (i % 2 == 0)
        {
            //If position of number is even
            changer += number % 10;
        }
        number /= 10;
    }
    storer += changer;  //Adds storer and changer
    long long twoDigitNumber = originalNumber / pow(10, (_length - 2));  //Gets the first two digits of credit card
    int visaTemp = twoDigitNumber / 10;
    if (storer % 10 != 0)
    {
        //If the number isn't divisible by 10, it's invalid
        printf("INVALID\n");
        _length = 0;
    }
    else if (_length == 15 && (twoDigitNumber == 34 || twoDigitNumber == 37))
    {
        //If it's 15 digits long and starts with 34 or 37, it's an amex
        printf("AMEX\n");
    }
    else if (_length == 16)
    {
        if (visaTemp == 4)
        {
            printf("VISA\n");
        }
        else if (twoDigitNumber > 50 && twoDigitNumber < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (_length == 13 && visaTemp == 4)
    {
        //If it's 13 digits long and starts with
        printf("VISA\n");
    }
    else
    {
        //If all else fails, it's not valid
        printf("INVALID\n");
    }
}

