
#include <stdio.h>
#include <pthread.h>
void *kidfunc(void *p)
{
  printf ("Kid ID is ---> %d\n", getpid( ));
  // printf ("Kid ID is ---> %d\n", pthread_self( ));
}
main ( )
{
pthread_t kid ;
pthread_create (&kid, NULL, kidfunc, NULL) ;
printf ("Parent ID is ---> %d\n", getpid( )) ;
// printf ("Parent ID is ---> %d\n", pthread_self( )) ;

pthread_join (kid, NULL) ;

printf ("No more kid!\n") ;
}
