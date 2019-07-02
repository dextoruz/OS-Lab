#include <stdio.h>
#include <pthread.h>
#include <time.h>

int array1[5] = {1,2,3,4,5};
int array2[5] = {1,2,3,4,5};

void *add(void*p){
    int a;
    a = (int *) p;
    array2[a] = array1[a]+array2[a];
    printf("-->>  %d\n",array2[a]);
}


main () {
  clock_t t ;
  t = clock();

  pthread_t threads[5];
  for (int i = 0; i<5; i++ ){
    int temp[2];
    int rc;

  rc = pthread_create(&threads[i],NULL, add, (void*) i);
  if(rc){
    printf("%s\n", "error");
  }
  pthread_join(threads[i],NULL);

}
t = clock() - t ;
printf("it took %d clicks or (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);

pthread_exit(NULL);
}
