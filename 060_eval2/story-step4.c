#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rand_story.h"

int main(int argc, char ** argv) {
  if ((argc != 3) && (argc != 4)) {
    fprintf(stderr, "Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f_words;
  FILE * f_story;
  size_t flag_n = 0;
  if (argc == 3) {
    f_words = fopen(argv[1], "r");
    if (f_words == NULL) {
      perror("Could not open file");
      return EXIT_FAILURE;
    }

    f_story = fopen(argv[2], "r");
    if (f_story == NULL) {
      perror("Could not open file");
      return EXIT_FAILURE;
    }
  }
  else {
    flag_n = 1;
    f_words = fopen(argv[2], "r");
    if (f_words == NULL) {
      perror("Could not open file");
      return EXIT_FAILURE;
    }

    f_story = fopen(argv[3], "r");
    if (f_story == NULL) {
      perror("Could not open file");
      return EXIT_FAILURE;
    }
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
    ParseAndPrintofStep1(curr1, cats, flag_n);
  }
  free(curr1);

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

  /* if (fclose(f_story) != 0) {
    perror("Could not close file words");
    return EXIT_FAILURE;
  }
  if (fclose(f_words) != 0) {
    perror("Could not close file story");
    return EXIT_FAILURE;
    }*/
  fclose(f_story);
  fclose(f_words);

  return EXIT_SUCCESS;
}
