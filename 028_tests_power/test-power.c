#include <stdio.h>
#include <stdlib.h>

unsigned int power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (expected_ans != power(x, y)) {
    printf("this program does not success");
    exit(EXIT_FAILURE);
  }
}

int main(void) {
  run_check(0, 0, 1);
  run_check(0, 1, 0);
  run_check(1, 0, 1);
  run_check(-2, 2, 4);
  run_check(-1, 1, 4294967295);
  return EXIT_SUCCESS;
}
