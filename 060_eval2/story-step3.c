#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rand_story.h"

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f_words = fopen(argv[1], "r");
  if (f_words == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }

  FILE * f_story = fopen(argv[2], "r");
  if (f_story == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }

  catarray_t * cats = malloc(sizeof(*cats));
  cats->arr = NULL;
  cats->n = 0;

  ssize_t len = 0;
  char * curr = NULL;
  size_t sz = 0;
  while ((len = getline(&curr, &sz, f_words)) >= 0) {
    ReadAndStore(curr, cats);
  }
  printWords(cats);
  free(curr);

  ssize_t len1 = 0;
  char * curr1 = NULL;
  size_t sz1 = 0;
  while ((len1 = getline(&curr1, &sz1, f_story)) >= 0) {
    ParseAndPrintofStep1(curr, len, cats);
  }
  free(curr1);

  return EXIT_SUCCESS;
}
