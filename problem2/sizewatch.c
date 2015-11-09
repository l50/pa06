/**
 * @file   sizewatch.c
 * @author Jayson Grace (jaysong@unm.edu)
 * @author Dominic Salas (dominic.salas@gmail.com)
 * @date   11/08/2015
 * @brief  Daemon to keep track of size changes that occur in a file over a 3 minute period.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void getTime()
{
    time_t currentTime;
    struct tm * timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    printf("[%d-%d-%d %d:%02d:%02d] ", (1 + timeInfo->tm_mon), timeInfo->tm_mday,  (1900+timeInfo->tm_year), timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}

int main(int argc, char* argv[])
{
    struct stat fileInfo;

    if(stat(argv[1], &fileInfo) == -1)
    {
        printf("Error: Input file not found!\n");
        return -1;
    }

    getTime();
    printf("Monitoring File: %s\n", argv[1]);

    off_t fileSize;
    fileSize = fileInfo.st_size;
    int i;

    getTime();
    printf("Initial Size: %d\n", (int) fileSize);

    for(i = 0; i < 18; i++)
    {
        if(stat(argv[1], &fileInfo) == -1)
        {
            printf("Error: The file has been moved or deleted!\n");
            return -1;
        }
        if((fileSize != fileInfo.st_size))
        {
            getTime();
            printf("Size Changed: Old: %d, New = %d\n", (int)fileSize, (int)fileInfo.st_size);
            fileSize = fileInfo.st_size;
        }
        sleep(10);
    }

    getTime();
    printf("Monitoring File terminated, BYE.\n");
}
