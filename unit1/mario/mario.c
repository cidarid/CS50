#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Initalization
    int height;
    bool validInput = false;
    do
    {
        height = get_int("Height: ");
        if (height > 23 || height < 0)
        {
            //If height is larger than 23 or negative it must be an invalid input
            validInput = false;
        }
        else
        {
            //If height is not larger than 23 or negative, it must be a valid input
            validInput = true;
        }
    }
    while (!validInput);
    for (int i = 0; i < height; i++)
    {
        //Loop that inserts one space for whatever number of iteration we're on
        for (int _i = height - i; _i > 1; _i--)
        {
            //Initial spaces away from rightmost corner
            printf(" ");
        }
        for (int _i = i + 1; _i > 0; _i--)
        {
            //First column
            printf("#");
        }
        printf("  "); //Dividing space
        for (int _i = i + 1; _i > 0; _i--)
        {
            //Second column
            printf("#");
        }
        printf("\n");      //Making new line for next runthrough
    }
}