#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
   pid_t pid;
   FILE *fp = NULL;

   /* Fork to create a child process.   */
   /* On success,  the PID of the child process is returned in the parent, 
    * and 0 is returned in the child.  On failure, -1 is returned in the 
    * parent, no child process is created, and errno is set appropriately.
    */
   pid = fork();

   /* Now both parent and child execute same code. */

   /* If pid is -1 then there was a failure in fork. */
   if ( pid < 0 )
   {
      printf("FORK FAILURE!\n");
      exit(EXIT_FAILURE);
   }

   if ( pid == 0 )
      printf("I am child process.\n");
   if ( pid > 0 )
      printf("I am parent process.\n");

   /* The pid of the child is returned in the parent so if pid is greater
    * than 0 then parent process will execute this code. In other words,
    * the parent process will exit and we will only have the child executing.
    */
   if ( pid > 0 )
   {
      exit(EXIT_SUCCESS);
   }

   printf("parent died, only child here now\n");

   fp = fopen ("log.txt", "w+");

   while ( 1 )
   {
      fprintf(fp, "Logging info...\n");
      fflush(fp);
      sleep(5);
   }

   fclose(fp);
   return 0;

}
