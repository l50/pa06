/**
 * @file   filetype.c
 * @author Jayson Grace (jaysong@unm.edu)
 * @author Dominic Salas (dominic.salas@gmail.com)
 * @date   11/05/2015
 * @brief  filetype program to identify files without dependence on its having an extension
 */

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum { false, true };

int getMagicNumber(FILE *file)
{
    unsigned char *fileInfo;
    long fileSize;
    fseek (file , 0 , SEEK_END);
    fileSize = ftell (file);
    rewind (file);
    fileInfo = (char *)malloc(fileSize+1);

    fread(fileInfo, sizeof(char), 4, file);
    printf("%02hhx%02hhx%02hhx%02hhx\n", fileInfo[0], fileInfo[1], fileInfo[2], fileInfo[3]);
    free(fileInfo);
    return 0;
}


/**
  @brief Entry into program
  @param argc Argument count
  @param argv Argument vector
  @return Success (or lackthereof) of program's execution
  */
int main(int argc, char **argv)
{
    if ( argc != 2 ) 
    {
        printf( "usage: %s filename", argv[0] );
    }
    else 
    {
        FILE *file = fopen( argv[1], "r" );

        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
//            readFile(file);
            getMagicNumber(file);
        }
    }
    return EXIT_SUCCESS;
}
