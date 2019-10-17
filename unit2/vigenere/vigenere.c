#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    char *input = argv[1];
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isalpha(input[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    char *temp = get_string("plaintext: ");
    unsigned char *textInput = (unsigned char *)temp;
    int inputPos = 0;
    bool capital;
    bool otherChar;
    for (int i = 0; i < strlen(temp); i++)
    {
        otherChar = !isalpha(textInput[i]);
        if (inputPos >= strlen(input))
        {
            inputPos = 0;
        }
        float modifier = input[inputPos];
        if (65 <= modifier && modifier <= 90)
        {
            modifier -= 65;
        }
        else if (97 <= modifier && modifier <= 122)
        {
            modifier -= 97;
        }
        if (65 <= textInput[i] && textInput[i] <= 90)
        {
            capital = true;
        }
        else if (97 <= textInput[i] && textInput[i] <= 122)
        {
            capital = false;
        }
        if (!otherChar)
        {
            //printf("b: %c, with modifier %i\n", textInput[i], modifier);
            textInput[i] = textInput[i] + modifier;
            //printf("p: %c\n", textInput[i]);
        }
        while (textInput[i] > 90 && capital == true && !otherChar)
        {
            textInput[i] -= 26;
        }
        while (textInput[i] > 122 && capital == false && !otherChar)
        {
            textInput[i] -= 26;
        }
        if (!otherChar)
        {
            inputPos++;
        }
    }
    printf("ciphertext: %s\n", textInput);
}