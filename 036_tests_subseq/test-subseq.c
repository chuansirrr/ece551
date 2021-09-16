#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

void run_check(int * array, size_t n, size_t expected) {
  if (maxSeq(array, n) != expected) {
    printf("this program does not success");
    exit(EXIT_FAILURE);
  }
}

int main(void) {
  int array1[] = {0, 1, 2, 3, 4, 5, 6};
  int array2[] = {0, 0, 0, 0, 0, 0};
  int array4[] = {7, 6, 5, 4, 3, 2, 1};
  int array5[] = {-1};
  int array6[] = {1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  int array7[] = {-4, -3, -2, 0, 3, 2, 1};

  run_check(array7, 7, 5);
  run_check(array1, 7, 7);
  run_check(array2, 6, 1);
  run_check(NULL, 0, 0);
  run_check(array4, 7, 1);
  run_check(array5, 1, 1);
  run_check(array6, 10, 4);
  return EXIT_SUCCESS;
}
