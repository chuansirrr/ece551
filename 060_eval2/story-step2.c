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

  printWords(cats);

  free(curr);

  for (size_t i = 0; i < cats->n; i++) {
    for (size_t j = 0; j < cats->arr[i].n_words; j++) {
      free(cats->arr[i].words[j]);
    }
  }
  for (size_t i = 0; i < cats->n; i++) {
    free(cats->arr[i].name);
    free(cats->arr[i].words);
  }
  free(cats->arr);
  free(cats);
  if (fclose(f) != 0) {
    perror("Could not close file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
