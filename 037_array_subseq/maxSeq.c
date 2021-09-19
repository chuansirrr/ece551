#include <stdio.h>
#include <stdlib.h>
size_t findseq(int * array, int n) {
  int * p = array;
  int * q = array + 1;
  size_t maxfseq = 1;
  for (size_t i = 1; i <= n - 1; i++) {
    if (*p < *q) {
      p = q;
      q = q + 1;
      maxfseq = maxfseq + 1;
    }
    else {
      break;
    }
  }
  return maxfseq;
}

size_t maxSeq(int * array, size_t n) {
  if (n == 1) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }

  size_t max;
  size_t max_q = 1;
  for (size_t j = 0; j <= n - 2; j++) {
    max = findseq(array + j, n - j);
    if (max > max_q) {
      max_q = max;
    }
  }
  return max_q;
}
