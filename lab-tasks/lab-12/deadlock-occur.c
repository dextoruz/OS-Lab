#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include <stdbool.h>
bool lock1 = false;
bool lock2=false;
int myGlobal = 0;
void *threadFunction1()
{
int i, j;
for (i = 0; i<10; i++)
{
printf("\n I am thread # 01 \n");
while(lock1);
lock1=true;
j = myGlobal;
j = j+1;
myGlobal = j;
sleep(1);
while(lock2);
lock2=true;
printf("\n My Global Is: %d\n", myGlobal);
lock2=false;
lock1=false;
}
}
void *threadFunction2()
{
int i, j;
for (i = 0; i<10; i++)

{
printf("\n I am thread # 02 \n");
while(lock2);
lock2=true;
j = myGlobal;
j = j+1;
myGlobal = j;
while(lock1);
lock1=true;
printf("\n My Global Is: %d\n", myGlobal);
lock1=false;
lock2=false;
}
}
int main()
{
pthread_t myThread1,myThread2;
int i,k;
pthread_create(&myThread1, NULL,threadFunction1,NULL);
pthread_create(&myThread2, NULL,threadFunction2,NULL);
pthread_join(myThread1, NULL);
pthread_join(myThread2, NULL);
exit(0);
}
