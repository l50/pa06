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

bool DEBUG = false;

/**
 * @brief Get the magic number from the input file
 * @param file The file to get the magic number from
 * @return Magic number
 */
unsigned char* getMagicNumber(FILE *file) 
{
  long fileSize;
  unsigned char *fileInfo;
  fseek(file, 0, SEEK_END);
  fileSize = ftell(file);
  rewind(file);
  fileInfo = (char *) malloc(fileSize + 1);


  fread(fileInfo, sizeof(char), 4, file);
  if (DEBUG)
  {
    printf("%02hhx%02hhx%02hhx%02hhx\n", fileInfo[0], fileInfo[1], fileInfo[2], fileInfo[3]);
    if (fileInfo[0] == 0x1f)
    {
      printf("%x\n", fileInfo[0]);
    }
  }
  return fileInfo;
}

/**
 * @brief Get the file type based on its magic number
 * @param fileInfo The information about the file
 */
void getFileType(char* fileInfo)
{
  int i;
  char pdf[4] = {0x25,0x50,0x44,0x00};
  char jpg[4] = {0xff,0xd8,0xff,0x00};
  char elf[4] = {0x7f,0x45,0x4c,0x00};
  char tar[4] = {0x1f,0x8b,0x08,0x00};
  char sh[4] = {0x23,0x21,0x2f,0x00};
  char result[4];
  for (i = 0; i < 3; i++)
  {
    result[i] = fileInfo[i];
    if (DEBUG)
      printf("%c\n", fileInfo[i]);
  }
  result[3] = 0x00;
  if (strcmp(pdf, result) == 0)
    printf("PDF detected\n");
  else if (strcmp(sh, result) == 0)
    printf("sh detected\n");
  else if (strcmp(elf, result) == 0)
    printf("ELF detected\n");
  else if (strcmp(tar, result) == 0)
    printf("tar.gz detected\n");
  else if (strcmp(jpg, result) == 0)
    printf("jpg detected\n");
  else
    printf("Invalid file type input!\n");
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
      return EXIT_FAILURE;
    }
    else
    {
      fileInfo = getMagicNumber(file);
      getFileType(fileInfo);
    }
  }
  free(fileInfo);
  return EXIT_SUCCESS;
}
