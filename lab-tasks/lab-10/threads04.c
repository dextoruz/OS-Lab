#include <pthread.h>
#include <stdio.h>
struct thread_data
{
int x, y,z;
};
struct thread_data somedata;
void *print(void *threadArg)
{
struct thread_data *my_data;
my_data = (struct thread_data *) threadArg;
printf("X: %d, Y: %d, Z: %d\n",my_data->x, my_data->y, my_data->z);
}
int main()
{
pthread_t tid;
somedata.x = 1;
somedata.y = 2;
somedata.z = somedata.x + somedata.y;
pthread_create(&tid, NULL, print, (void *) &somedata);
pthread_join(tid, NULL );
}
