#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void collatz(int n, int i);
void sum(int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    //collatz(n, -1);
    sum(n);
}

void collatz(int n, int i)
{
    i++;
    if (n == 1) {
        printf("we have succeeded, it took us %i iterations. \n", i);
    }
    else if (n % 2 == 0) {
        collatz(n /= 2, i);
    }
    else if (n % 2 != 0) {
        collatz(3 * n + 1, i);
    }
}

void sum(int n) {
    if (n == 1) {
        printf("%i", n);
        return;
    }
    printf("%i", n);
    sum(n-1);
}