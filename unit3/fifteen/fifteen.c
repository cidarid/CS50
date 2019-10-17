// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);
void movetile(int tile, int row, int col);


int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    return;
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(20000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    // TODO
    int index = d  * d - 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (index != 0)
            {
                if (index == 1 && d % 2 == 0)
                {
                    board[i][j] = 2;
                    board[i][j - 1] = 1;
                    index--;
                }
                else
                {
                    board[i][j] = index;
                    index--;
                }
            }
        }
    }

    blank_row = d - 1;
    blank_col = d - 1;
}

// Prints the board in its current state
void draw(void)
{
    // TODO
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != 0)
            {
                if (board[i][j] < 10)
                {
                    printf(" ");
                }
                printf("%i ", board[i][j]);
            }
            else
            {
                printf(" _ ");
            }
        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    int possibleMoves[2] = {-1, 1};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0)
            {
                if (board[blank_row + possibleMoves[j]][blank_col] == tile)
                {
                    movetile(tile, blank_row + possibleMoves[j], blank_col);
                    return true;
                }
            }
            if (i == 1)
            {
                if (board[blank_row][blank_col + possibleMoves[j]] == tile)
                {
                    movetile(tile, blank_row, blank_col + possibleMoves[j]);
                    return true;
                }
            }
        }
    }
    return false;
}

void movetile(int tile, int row, int col)
{
    board[row][col] = 0;
    board[blank_row][blank_col] = tile;
    blank_row = row;
    //printf("Blank row is now %i\n", blank_row);
    blank_col = col;
    //printf("Blank column is now %i\n", blank_col);
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    int index = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (index == d * d)
            {

            }
            else if (board[i][j] != index)
            {
                //printf("row %i and column %i are not equal to %i. ", i, j, index);
                return false;
            }
            index++;
        }
    }
    return true;
}


