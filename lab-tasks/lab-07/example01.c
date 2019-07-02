#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(int argc,char *argv[])
{
printf("%d",argc);
argv[0]="/bin/ls";
int pid;
pid=fork();
if(pid<0)
{
printf("fork failed");
exit(1);
}
else if(pid==0)
{
  execve( argv[0],argv,NULL);
  }
  else
  {
  printf("\n Process id is -%d\n",getpid());
  wait(NULL);
  exit(0);
  } }
