#include <pthread.h>
#include <stdio.h>
void *PrintHello(void *threadid)
{
printf("\n%d: Hello World!\n", threadid);
pthread_exit(NULL);
}
int main()
{
pthread_t threads[3];
int rc;
int t;
for(t=0; t<3; t++)
{
printf("In main: creating thread\n", t);
rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
if (rc)
{
printf("ERROR; return code from pthread_create() is %d\n", rc);
exit(-1);
}
pthread_join(threads[t], NULL );
}
pthread_exit(NULL);
}
