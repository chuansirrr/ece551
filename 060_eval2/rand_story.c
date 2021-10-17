#include "rand_story.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ParseAndPrintofStep1(char * str1, size_t len) {
  char * str1cp = str1;
  //copy returned word
  const char * cat1 = chooseWord("verb", NULL);
  char cat[20];  //number of characters of word + 1('\0')
  size_t countcat1 = 0;
  while (*(cat1 + countcat1) != '\0') {
    cat[countcat1] = *(cat1 + countcat1);
    countcat1++;
  }
  cat[countcat1] = '\0';

  char str[100];
  char * place1 = strchr(str1, '_');
  size_t curri = 0;

  while ((*place1 != '\0')) {
    char * place2 = strchr(place1 + 1, '_');
    place2++;

    while (str1cp != place1) {
      str[curri] = *str1cp;
      str1cp++;
      curri++;
    }

    char * catcp = cat;
    while (*catcp != '\0') {
      str[curri] = *catcp;
      catcp++;
      curri++;
    }

    while ((*place2 != '_') && (*place2 != '\0')) {
      str[curri] = *place2;
      place2++;
      curri++;
    }
    place1 = place2;
    str1cp = place2;
  }
  str[curri] = '\0';
  printf("%s", str);
}
