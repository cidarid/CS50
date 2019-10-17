#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float c = get_float("C: "); //Gets temperature input from user
    float convertedc = ((c * 9) / 5) + 32; //Converts celsius to fahrenheit
    printf("F: %.1f\n",  convertedc); //Prints the converted value
}