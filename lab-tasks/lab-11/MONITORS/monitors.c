#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int balance = 0;
pthread_mutex_t monitor;

void *deposit(void * amount) {
  int am;
  am = (int*) amount;
pthread_mutex_lock(&monitor);
balance = balance + am;
printf("%d\n", balance);
pthread_mutex_unlock(&monitor);
}

void *withdraw(void *amount) {
  int am;
  am = (int*) amount;
pthread_mutex_lock(&monitor);
balance = balance - am;
printf("%d\n", balance);
pthread_mutex_unlock(&monitor);
}


int main() {
  pthread_t a,b,c,d ;
  int amount = 1000;
  balance = amount;
  printf("-->> %d\n", balance);
  pthread_create (&a, NULL, withdraw, (void*) amount);
  amount = 300;
  pthread_create (&b, NULL, deposit, (void*) amount);
  amount = 300;
  pthread_create (&a, NULL, deposit, (void*) amount);
  amount = 300;
  pthread_create (&b, NULL, withdraw, (void*) amount);

  pthread_join (a, NULL) ;
  pthread_join (b, NULL) ;
  // pthread_join (c, NULL) ;
  // pthread_join (d, NULL) ;
  printf("%d\n", balance );
exit(0);

}
