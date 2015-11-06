/**
 * @file   filetype.c
 * @author Jayson Grace (jaysong@unm.edu)
 * @author Dominic Salas (dominic.salas@gmail.com)
 * @date   11/05/2015
 * @brief  filetype program to identify files without dependence on its having an extension
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
enum { false, true };

bool DEBUG = true;

unsigned char* getMagicNumber(FILE *file)
{
    long fileSize;
    unsigned char *fileInfo;
    fseek (file , 0 , SEEK_END);
    fileSize = ftell (file);
    rewind (file);
    fileInfo = (char *)malloc(fileSize+1);


    fread(fileInfo, sizeof(char), 4, file);
    if (DEBUG)
    printf("%02hhx%02hhx%02hhx%02hhx\n", fileInfo[0], fileInfo[1], fileInfo[2], fileInfo[3]);
    return fileInfo;
}

void getFileType(char* fileInfo)
{
    int i, j;
    char pdf[3] = "PDF"; 
    char jpg[3] = "jpg";
    char elf[3] = "ELF";
    char tar[3] = "tar";
    char sh[3] = "sh";
    char result[3];
    bool pdfFound = false;
    for (i = 1, j = 0; i < 4; i++)
    {
        result[j] = fileInfo[i];
        if (DEBUG)
            printf("%c\n", fileInfo[i]);
    }
    if (strcmp(pdf, result))
        printf("PDF detected");
    else if (strcmp(sh, result))
        printf("sh detected");
    else if (strcmp(elf, result))
        printf("ELF detected");
    else 
        printf("Invalid file type input!");
}



/**
  @brief Entry into program
  @param argc Argument count
  @param argv Argument vector
  @return Success (or lackthereof) of program's execution
  */
int main(int argc, char **argv)
{
    char* fileInfo;
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
            fileInfo = getMagicNumber(file);
            getFileType(fileInfo);
        }
    }
    free(fileInfo);
    return EXIT_SUCCESS;
}
