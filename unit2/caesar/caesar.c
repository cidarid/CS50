#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    char *_cipher = argv[1];
    int cipher = atoi(_cipher);
    char *input = get_string("plaintext: ");
    int stringLength = strlen(input);
    int store;
    int modified;
    bool capital;
    bool space = false;
    bool done;
    printf("ciphertext: ");
    for (int i = 0; i < stringLength; i++)
    {
        done = false;
        if (65 <= input[i] && input[i] <= 90)
        {
            capital = true;
        }
        else if (97 <= input[i] && input[i] <= 122)
        {
            capital = false;
        }
        else
        {
            goto no;
        }
        modified = input[i] + cipher;
        while (modified > 90 && capital == true && space == false)
        {
            modified -= 26;
        }
        while (modified > 122 && capital == false && space == false)
        {
            modified -= 26;
        }
        printf("%c", modified);
        done = true;
no:
        if (!done)
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}