#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void breakc(FILE * f) {
  int c;
  int everyencryptfq[26] = {0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      everyencryptfq[c] += 1;
    }
  }
  int max = 0;
  int j = 0;
  for (int i = 0; i < 26; i++) {
    if (max < everyencryptfq[i]) {
      max = everyencryptfq[i];
      j = i;
    }
  }

  int ans = (26 + 'a' + j - 'e') % 26;

  printf("%d\n", ans);
}

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

  breakc(f);

  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
