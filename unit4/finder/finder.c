// Recursively searches for a query in a directory.

#define _BSD_SOURCE
#define _GNU_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAXLENGTH 50

// Struct to hold the file name and type
typedef struct
{
    string name;
    string type;
    bool printed;
}
path;

// Struct to hold the directory info
typedef struct
{
    string name;
    int npaths;
    path *paths;
}
directory;

// String to hold the word to seek
string key;

// The function to search for files in a directory and populate the struct
directory populate(directory dir);

// The function to recursively iterate through directories and handle files
int seek(directory dir);


int main(int argc, char *argv[])
{

    // TODO: ensure proper number of command line arguments

    // Create initial directory and set name string
    directory dir;
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./finder searchstring filepath/\n");
        return 1;
    }
    if (argc == 3)
    {
        char *str = argv[2];
        if (!(str && *str && str[strlen(str) - 1] == '/'))
        {
            printf("File name does not end with a /.\n");
            return 2;
        }
        dir.name = str;
    }
    else
    {
        dir.name = "./";
    }
    key = argv[1];
    // TODO: set "dir"s name based on command line arguments entered

    return seek(populate(dir));
}

directory populate(directory dir)
{
    // Initialize all pointers and values in the given struct
    dir.npaths = 0;
    dir.paths = NULL;
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir(dir.name);
    if (dirp == NULL)
    {
        printf("Opening directory failed. Check your input filepath!\n");
        return dir;
    }

    while ((entry = readdir(dirp)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 2);
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            strcat(name, "/");

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "directory"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }

        // Else if entry is a file, increase file count and populate the struct
        else if (entry->d_type == DT_REG)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 1);
            strcat(name, dir.name);
            strcat(name, entry->d_name);

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "file"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }
    }

    // Close directory stream using system call closedir and return struct
    closedir(dirp);
    return dir;
}

// Recursive function to iterate through directories and search files
int seek(directory dir)
{
    int pos = 0;
    if (strcmp(dir.paths[pos].type, "file") == 0)
    {
        FILE *ptr1 = fopen(dir.paths[pos].name, "r");
        char fileRead[128];
        fgets(fileRead, 128, ptr1);
        string found = strstr(fileRead, key);
        if (found != NULL)
        {
            FILE *writeFile = fopen("./found.txt", "a");
            if (dir.paths[pos].printed == false)
            {
                fprintf(writeFile, "%s\n", dir.paths[pos].name);
                dir.paths[pos].printed = true;
            }
            fclose(writeFile);
        }
        fclose(ptr1);
    }
    else if (strcmp(dir.paths[pos].type, "directory") == 0)
    {
        directory nDir;
        nDir.name = dir.paths[pos].name;
        seek(populate(nDir));
    }
    //FILE *ptr1 = fopen(dir.name, "r");
    /*if (ptr1 == NULL) {
        printf("Error opening file.\n");
        return -2;
    }
    //Prints the letters in a file
    char ch;
    while ((ch = fgetc(ptr1)) != EOF) {
        printf("%c", ch);
    }
    //String to add to file
    char str[] = "eristeinschwuchtel";
    //Writes string to file
    fwrite(str, 1, sizeof(str), ptr1);
    //Closes (and saves) file*/
    // TODO
    return -1;
}