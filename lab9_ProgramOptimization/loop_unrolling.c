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

  /* Test */
  clock_t start = clock();
  long long sum = 0;

  for (unsigned i = 0; i < 100000; ++i) {
    /* Primary loop */
    for (unsigned c = 0; c < arraySize; c += 8) { /*loop unrolling trick*/
      // arraySize is divisible by 8
      if (data[c] >= 128)
        sum += data[c];
      if (data[c + 1] >= 128)
        sum += data[c + 1];
      if (data[c + 2] >= 128)
        sum += data[c + 2];
      if (data[c + 3] >= 128)
        sum += data[c + 3];
      if (data[c + 4] >= 128)
        sum += data[c + 4];
      if (data[c + 5] >= 128)
        sum += data[c + 5];
    }
  }
  double elapsedTime = ((double)(clock() - start)) / CLOCKS_PER_SEC;

  printf("elapsedTime = %f\n", elapsedTime);
  printf("sum = %llu\n", sum);
}