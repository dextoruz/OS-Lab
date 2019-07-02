#include <stdio.h>
#include <pthread.h>
#include <time.h>

int array1[5] = {1,2,3,4,5};
int array2[5] = {1,2,3,4,5};

void add(int a){

    array2[a] = array1[a]+array2[a];
    printf("-->>  %d\n",array2[a]);
}

main(){
  clock_t t ;
  t = clock();

  //pthread_t threads[5];
  for (int i = 0; i<5; i++ ){
    add(i);
  }
  
t = clock() - t ;
printf("it took %d clicks or (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);


}
