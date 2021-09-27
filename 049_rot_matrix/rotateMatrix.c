#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 10
void rotate(FILE * f) {
  char newmatrix[10][10];
  char line[LINE_SIZE + 2];
  size_t hight_flag = LINE_SIZE;
  size_t nthline = 0;
  while (fgets(line, LINE_SIZE + 2, f) != NULL) {
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Line is too long!\n");
      exit(EXIT_FAILURE);
    }

    hight_flag -= 1;
    if (hight_flag < 0) {
      fprintf(stderr, "The Matrix is too high!\n");
      exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < LINE_SIZE; i++) {
      if (line[i] == '\n') {
        fprintf(stderr, "Line is too short!\n");
        exit(EXIT_FAILURE);
      }
      newmatrix[i][LINE_SIZE - 1 - nthline] = line[i];
    }
    nthline += 1;
  }

  if (hight_flag > 0) {
    fprintf(stderr, "The Matrix is too short!\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < LINE_SIZE; i++) {
    for (size_t j = 0; j < LINE_SIZE; j++) {
      printf("%c", newmatrix[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open file");
    return EXIT_FAILURE;
  }

  rotate(f);

  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
