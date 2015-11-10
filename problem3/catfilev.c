/**
 * @file   catfilev.c
 * @author Jayson Grace (jaysong@unm.edu)
 * @author Dominic Salas (dominic.salas@gmail.com)
 * @date   11/09/2015
 * @brief Print out content of file specified in mini file system by its inode number.
 * @params Number of inode; Path to directory with desired file to read
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

typedef int bool;
enum { false, true };

bool DEBUG = false;

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("Usage: %s [directory]\n", *argv);
        exit(0);
    }

    struct dirent *file;
    int inum = atoi(argv[1]);
    DIR *directory = opendir(argv[2]);
    while ((file = readdir(directory)) != NULL)
    {
        if (DEBUG)
        {
            printf("inode %d is for file %s\n",
                   file->d_ino, file->d_name);
        }

        if (file->d_ino == inum)
        {
            int c;
            FILE *epicFile;

            char* filepath;
            filepath = malloc(strlen(argv[2])+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(filepath, argv[2]); /* copy name into the new var */
            strcat(filepath, file->d_name); /* add the extension */
            
            epicFile = fopen(filepath, "r");
            if (epicFile)
            {
                while ((c = getc(epicFile)) != EOF)
                    putchar(c);
                fclose(epicFile);
            }
        }
    }

    closedir(directory);
    return EXIT_SUCCESS;
}