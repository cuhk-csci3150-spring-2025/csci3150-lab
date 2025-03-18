#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  /* Generate data */
  const unsigned arraySize = 32768;
  int data[arraySize];
  srand((int)123);

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = rand() % 256;

  qsort(data, arraySize, sizeof(int), cmpfunc);

  /* !!! With this, the next loop runs faster */

  /* Test */
  clock_t start = clock();
  long long sum = 0;

  for (unsigned i = 0; i < 100000; ++i) {
    /* Primary loop */
    for (unsigned c = 0; c < arraySize; ++c) {
      int t = (data[c] - 128) >> 31;
      sum += ~t & data[c];
    }
  }
  double elapsedTime = ((double)(clock() - start)) / CLOCKS_PER_SEC;

  printf("elapsedTime = %f\n", elapsedTime);
  printf("sum = %llu\n", sum);
}