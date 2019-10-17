// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int divPos = -1;
    int x = 0;
    int y = 0;
    bool eighths = false;
    for (int i = 0; i < strlen(fraction); i++)
    {
        if (fraction[i] == '/')
        {
            divPos = i;
        }
        else if (divPos == -1)
        {
            x *= 10;
            x += (fraction[i] - 48);
        }
        else
        {
            y *= 10;
            y += (fraction[i] - 48);
        }
    }
    while (!eighths)
    {
        if (y == 8)
        {
            eighths = true;
        }
        else if (y > 8)
        {
            y /= 2;
            x /= 2;
        }
        else if (y < 8)
        {
            y *= 2;
            x *= 2;
        }
    }
    return x;
    // TODO
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    /*int letterPos = note[0] - 64;
    int octave;
    int accidental = 0;

    if (note[1] == '#' || note[1] == 'b')
    {
        (note[1] == '#') ? (accidental = 1) : (accidental = -1);
        octave = note[2] - 48;
    }
    else
    {
        octave = note[1] - 48;
    }
    int _octave = (octave - 4) * 8;
    //printf("_octave: %f\n", _octave);
    int _letterPos;
    if (letterPos > 2) {
        _letterPos = letterPos - 8;
    } else {
        _letterPos = letterPos - 1;
    }
    printf("%i", accidental);
    int n = _octave + _letterPos + accidental;
    double f = pow(2, n/12);
    f *= 440;
    //printf("%f\n", f);
    int _f = round(f);
    //printf("%i\n", _f);
    return _f;
    // TODO*/
    int octave = note[strlen(note) - 1] - '0';

    // Base frequency of A4 is 440hz
    double freq = 440.0;

    // Adjust for letter
    switch (note[0])
    {
        case 'C':
            freq /= pow(2.0, 9.0 / 12.0);
            break;

        case 'D':
            freq /= pow(2.0, 7.0 / 12.0);
            break;

        case 'E':
            freq /= pow(2.0, 5.0 / 12.0);
            break;

        case 'F':
            freq /= pow(2.0, 4.0 / 12.0);
            break;

        case 'G':
            freq /= pow(2.0, 2.0 / 12.0);
            break;

        case 'A':
            break;
        case 'B':
            freq *= pow(2.0, 2.0 / 12.0);
            break;
    }

    // Adjust for octave
    if (octave > 4)
    {
        freq *= pow(2.0, octave - 4);
    }
    else if (octave < 4)
    {
        freq /= pow(2.0, 4 - octave);
    }

    // Adjust for accidental
    if (note[1] == 'b')
    {
        freq /= pow(2.0, 1.0 / 12.0);
    }
    else if (note[1] == '#')
    {
        freq *= pow(2.0, 1.0 / 12.0);
    }

    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // TODO
}
