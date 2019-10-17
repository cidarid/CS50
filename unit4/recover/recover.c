#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover jpeg\n");
        return 1;
    }
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *img = NULL;

    unsigned char buffer[512];
    char filename[8];

    int counter = 0;

    bool flag = false;

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (flag)
            {
                fclose(img);
            }
            else
            {
                flag = true;
            }

            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }s

        if (flag)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    fclose(inptr);
    fclose(img);

    return 0;
}