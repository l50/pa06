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
#include <syslog.h>

typedef int bool;
enum { false, true };

FILE * outputLog;

int fprintf(FILE *stream, const char *format, ...);

void getTime()
{
  time_t currentTime;
  struct tm * timeInfo;
  time(&currentTime);
  timeInfo = localtime(&currentTime);
  fprintf(outputLog, "[%d-%d-%d %d:%02d:%02d] ", (1 + timeInfo->tm_mon), timeInfo->tm_mday,  (1900+timeInfo->tm_year), timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}

/**
 * @brief Entry into program
 * @param argc Argument count
 * @param argv Argument vector
 * @return Success (or lackthereof) of program's execution
 */
int main(int argc, char* argv[])
{
  struct stat fileInfo;

  pid_t pid, sid;

  // Fork off parent
  pid = fork();

  // General error check for failure to generate child pid
  if (pid < 0)
  {
    exit(EXIT_FAILURE);
  }

  // Error check to determine if we can exit parent process
  if (pid > 0)
  {
    exit(EXIT_SUCCESS);
  }

  // Change file mode mask
  umask(0);

  // Open output log
  outputLog = fopen ("output.txt", "w+");

  // Create new SID for child process
  sid = setsid();
  if (sid < 0)
  {
    exit(EXIT_FAILURE);
  }

  if(stat(argv[1], &fileInfo) == -1)
  {
    fprintf(outputLog, "Error: Input file not found!\n");
    return -1;
  }

  getTime();
  fprintf(outputLog, "Monitoring File: %s\n", argv[1]);

  off_t fileSize;
  fileSize = fileInfo.st_size;
  int i;

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  getTime();
  fprintf(outputLog, "Initial Size: %d\n", (int) fileSize);

  for(i = 0; i < 18; i++)
  {
    if(stat(argv[1], &fileInfo) == -1)
    {
      fprintf(outputLog, "Error: The file has been moved or deleted!\n");
      return -1;
    }
    if((fileSize != fileInfo.st_size))
    {
      getTime();
      fprintf(outputLog, "Size Changed: Old: %d, New = %d\n", (int)fileSize, (int)fileInfo.st_size);
      fileSize = fileInfo.st_size;
    }
    sleep(10);
  }

  getTime();
  fprintf(outputLog, "Monitoring File terminated, BYE.\n");
  fclose(outputLog);
  return EXIT_SUCCESS;
}
