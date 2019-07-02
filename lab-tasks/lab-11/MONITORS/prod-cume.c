#include<iostream>
#include<pthread.h>
#include<unistd.h>
#define MAX 10
using namespace std;
class BoundedBuffer
{
private:
  int buffer[MAX];
  int fill, use;
  int fullEntries;
  pthread_mutex_t monitor;  // monitor lock
  pthread_cond_t empty;
  pthread_cond_t full;
public:
  BoundedBuffer ()
  {
    use = fill = fullEntries = 0;
  }
  void produce (int element)
  {
    pthread_mutex_lock (&monitor);
    while (fullEntries == MAX)
      pthread_cond_wait (&empty, &monitor);
    buffer[fill] = element;
    fill = (fill + 1) % MAX;
    fullEntries++;
    //sleep(rand()%2);
    pthread_cond_signal (&full);
    pthread_mutex_unlock (&monitor);
  }
  int consume ()
  {
    pthread_mutex_lock (&monitor);
    while (fullEntries == 0)
      pthread_cond_wait (&full, &monitor);
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    fullEntries--;
    //sleep(rand()%2);
    pthread_cond_signal (&empty);
    pthread_mutex_unlock (&monitor);
    return tmp;
  }
}b;
void* producer(void *arg){
int i=1;
while(true){
b.produce(i);
i++;
}
}
void* consumer(void *arg){
while(true){
cout<<b.consume()<<" ";
fflush(stdout);
}
}
int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,producer,NULL);
pthread_create(&t2,NULL,consumer,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
