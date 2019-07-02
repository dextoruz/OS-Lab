#include<iostream>
#include<pthread.h>
#include<unistd.h>
#define MAX 3
using namespace std;

static pthread_mutex_t monitor; // monitor lock
class BoundedBuffer {
  private:
    int buffer[MAX];
    int fill, use;
    int fullEntries;
    pthread_cond_t empty;
    pthread_cond_t full;
  public:
    BoundedBuffer() {
      use = fill = fullEntries = 0;
  }
    void *producer(int element) {
      pthread_mutex_lock(&monitor);
      if(fullEntries == MAX){

        // pthread_cond_wait(&empty, &monitor);
        buffer[fill] = element;
        fill = (fill + 1);
        fullEntries++;
        printVal();
        // pthread_cond_signal(&full);
      }
      else{
        buffer[fill] = element;
        fill = (fill + 1);
        fullEntries++;
        printVal();
      }
      pthread_mutex_unlock(&monitor);
  }
  int *consumer() {
    pthread_mutex_lock(&monitor);
    int *tmp;
      if(fullEntries == 0){

        // pthread_cond_wait(&full, &monitor);
        *tmp = buffer[use];
        use = (use + 1);
        fullEntries--;
        printVal();
        // pthread_cond_signal(&empty);
      }
      else{
        *tmp = buffer[use];
        use = (use + 1);
        fullEntries--;
        printVal();
      }
    pthread_mutex_unlock(&monitor);
    return tmp;
  }
  void printVal(){
    cout<<"fill = "<<fill<<endl<<"use = "<<endl<<"fullEntries = "<<endl;
    for(int i = 0; i<MAX; i++)
      cout<<"buffer "<<i+1<<" = "<<buffer[i]<<endl;
  }
};

struct arguments{
  BoundedBuffer *buffer;
  int element;
};

class temp_buffer {
public:
  static void *producer_helper(void *arg){
     return ((arguments *)arg)->buffer->producer(((arguments *)arg)->element);
  }

  static void *consumer_helper(void *arg){
     return ((arguments *)arg)->buffer->consumer();
  }

};
int main(){

  arguments argument1,argument2;
  pthread_t t0,t1,t2,t3;
  BoundedBuffer c;
  temp_buffer temp;

  int x=10000;
  int y = 500;

  argument1.buffer = &c;
  argument1.element = x;

  argument2.buffer = &c;
  argument2.element = y;

  pthread_create(&t0, NULL, &temp.producer_helper, &argument1);
  pthread_create(&t1, NULL, &temp.consumer_helper, &c);
  // pthread_create(&t2, NULL, &temp.producer_helper, &argument2);
  // pthread_create(&t3, NULL, &temp.consumer_helper, &c);

  pthread_join(t0,NULL);
  pthread_join(t1,NULL);
  // pthread_join(t2,NULL);
  // pthread_join(t3,NULL);

return 0;
}
