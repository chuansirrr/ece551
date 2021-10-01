#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function is used to figure out the ordering of the strings
//in qsort. You do not need to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void readData(FILE * f) {
  char ** line = NULL;
  char * c = NULL;
  size_t linecap;
  size_t i = 0;
  while (getline(&c, &linecap, f) >= 0) {
    line = realloc(line, (i + 1) * sizeof(*line));
    line[i] = c;
    c = NULL;
    i++;
  }
  free(c);

  sortData(line, i);
  for (size_t j = 0; j < i; j++) {
    printf("%s", line[j]);
    free(line[j]);
  }

  free(line);
}

int main(int argc, char ** argv) {
  //WRITE YOUR CODE HERE!
  if (argc == 1) {
    // printf("No input file provided.\nType strings to be sorted.\nPress CTRL+d to indicate EOF.\n");
    readData(stdin);
  }
  else {
    int i;
    for (i = 1; i < argc; i++) {
      FILE * f = fopen(argv[i], "r");
      if (f == NULL) {
        fprintf(stderr, "Could not open file");
        return EXIT_FAILURE;
      }

      readData(f);

      if (fclose(f) != 0) {
        fprintf(stderr, "Failed to close the input file!");
        return EXIT_FAILURE;
      }
    }
  }

  return EXIT_SUCCESS;
}
