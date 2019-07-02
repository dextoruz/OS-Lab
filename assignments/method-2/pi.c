#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
  clock_t begin = clock();
  char *str = argv[1];
  char *e;
  long STEPS = atoi(str);
  double x, y, z, pi;
  long count = 0;
  for (int i = 0; i <= STEPS; i++)
  {
    x = rand()/(double)RAND_MAX;
    y = rand()/(double)RAND_MAX;
    z = x*x + y*y;
    if (z <= 1)
      count++;
  }
  pi = (double)count/STEPS*4;
  // printf("N = %lu\t", STEPS);
  // printf("Pi = %.20lf\n", pi);

  clock_t end = clock();
  double time = (long double)(end - begin) / CLOCKS_PER_SEC;

  FILE *file = fopen("g.txt", "a+");
  fprintf(file, "%lu %lf %lf\n", STEPS,time,pi);
  fclose(file);
  return 0;
}
