#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()  {
 printf("whats my name = \n");
  pid_t processId = fork();
   printf("pid = %d\n",getpid());
   printf("parent pid = %d\n",getppid());

  printf("varender");
  return 0;
}
