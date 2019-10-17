# Questions

## What's `stdint.h`?

BMP related data types based on Microsoft's own

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Smaller data spaces, uint means it's unsigned, int means it's signed.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8 bits, 32 bits, 32 bits, 16 bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

bfSize is the size in bytes of the bitmap file, while biSize is the number of bytes required by the structure

## What does it mean if `biHeight` is negative?

The origin of the bitmap is the top left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file doesn't exist or if it doesn't have permission to write to a directory

## Why is the third argument to `fread` always `1` in our code?

Because we are only passing it one element

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Moves file pointer to the given position.

## What is `SEEK_CUR`?

Moves the file pointer to a specific location

## Whodunit?

It was Professor Plum, with the candlestick, in the library.
