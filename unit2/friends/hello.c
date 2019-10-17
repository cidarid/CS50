#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //If too many or too few arguments throw error
        printf("Usage: ./hello <name>\n");
        return 1;
    }
    //Print the arguments to the command line
    printf("Hello, %s!\n", argv[argc - 1]);
}