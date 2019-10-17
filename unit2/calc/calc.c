#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    string possibleInputs[] = {"+", "-", "x", "/", "%"};
    bool valid = false;
    if (argc != 4)
    {
        printf("Error, invalid amount of inputs.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(possibleInputs[i], argv[2]) == 0)
        {
            valid = true;
        }
    }
    if (!valid)
    {
        printf("Error, invalid operator.\n");
        return 1;
    }
    float x = atof(argv[1]);
    float y = atof(argv[3]);
    float z = 0;
    if (strcmp(argv[2], "+") == 0)
    {
        z = x + y;
    }
    else if (strcmp(argv[2], "-") == 0)
    {
        z = x - y;
    }
    else if (strcmp(argv[2], "x") == 0)
    {
        z = x * y;
    }
    else if (strcmp(argv[2], "/") == 0)
    {
        z = x / y;
    }
    else if (strcmp(argv[2], "%") == 0)
    {
        z = fmod(x, y);
    }
    printf("%f\n", z);
}