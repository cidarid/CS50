#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //If too many or too few arguments throw error
        printf("Usage: ./fahrenheit <temperature>\n");
        return 1;
    }
    float c = atof(argv[1]); //Gets temperature input from user
    float convertedc = ((c * 9) / 5) + 32; //Converts celsius to fahrenheit
    printf("F: %.1f\n",  convertedc); //Prints the converted value
}