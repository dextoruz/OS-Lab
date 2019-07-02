#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
  clock_t begin = clock();

  char *str = argv[1];
  char *e;
  long long STEPS = strtoll(str,&e,0);
  long double x, y, z, pi;
  long long count = 0;
  for (int i = 0; i <= STEPS; i++)
  {
    x = rand()/(double)RAND_MAX;
    y = rand()/(double)RAND_MAX;
    z = x*x + y*y;
    if (z <= 1)
      count++;
  }
  pi = (long double)count/STEPS*4;
  // printf("N = %llu\t", STEPS);
  // printf("Pi = %.20Lf\n", pi);


  clock_t end = clock();
  long double time_spent = (long double)(end - begin) / CLOCKS_PER_SEC;
  // printf("\nExecution time = %Lf seconds.\n", time_spent);


  FILE *f = fopen("graph.csv", "a+");
  if (f == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }
  fprintf(f, "%llu,%Lf,%Lf\n", STEPS,time_spent,pi);
  fclose(f);

  return 0;
}
