#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("");
    bool firstInitial = true;
    bool space = false;
    for (int i = 0; i < strlen(s); i++)
    {
        unsigned char temp = s[i];
        if (temp == ' ')
        {
            if (firstInitial == false)
            {
                firstInitial = true;
            }
            space = true;
        }
        else
        {
            space = false;
        }
        if (!space && firstInitial)
        {
            firstInitial = false;
            temp = toupper(temp);
            printf("%c", temp);
        }
    }
    printf("\n");
}