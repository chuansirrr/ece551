#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rand_story.h"

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }

  catarray_t * cats = malloc(sizeof(*cats));
  cats->arr = NULL;
  cats->n = 0;

  ssize_t len = 0;
  char * curr = NULL;
  size_t sz = 0;
  while ((len = getline(&curr, &sz, f)) >= 0) {
    ReadAndStore(curr, cats);
  }
  //getline(&curr, &sz, f);
  //ReadAndStore(curr, cats);
  //getline(&curr, &sz, f);
  //ReadAndStore(curr, cats);
  printWords(cats);

  free(curr);
  return EXIT_SUCCESS;
}
