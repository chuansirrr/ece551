#include "rand_story.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ParseAndPrintofStep1(char * str1, catarray_t * cats, size_t flag_n) {
  char * countof_num = str1;
  size_t countof_numnum = 0;
  while (*countof_num != '\0') {
    if (*countof_num == '_') {
      countof_numnum++;
    }
    countof_num++;
  }
  if (countof_numnum % 2 != 0) {
    fprintf(stderr, "'_' is not even");
    exit(EXIT_FAILURE);
  }

  char * str1cp = str1;
  //copy returned word

  char str[100];
  char * place1 = strchr(str1, '_');
  size_t curri = 0;

  //////////used words////////////

  size_t CountUsedNum = 0;
  char ** StoreUsedNum = NULL;
  ////////////use to free///////////////

  //////////used words////////////
  while ((*place1 != '\0')) {
    char * place2 = strchr(place1 + 1, '_');
    place2++;

    while (str1cp != place1) {
      str[curri] = *str1cp;
      str1cp++;
      curri++;
    }
    /*******************************/

    char getcateg[15];
    size_t getcategi = 0;
    char * place1cp = place1;
    while (*(place1cp + 1 + getcategi) != '_') {
      getcateg[getcategi] = *(place1cp + 1 + getcategi);
      getcategi++;
    }
    getcateg[getcategi] = '\0';

    CountUsedNum++;

    char cat[20];  //number of characters of word + 1('\0')
    size_t countcat1 = 0;
    char * catcp = cat;

    if (!atoi(getcateg)) {
      const char * cat1 = chooseWord(getcateg, cats);

      while (*(cat1 + countcat1) != '\0') {
        cat[countcat1] = *(cat1 + countcat1);
        countcat1++;
      }
      cat[countcat1] = '\0';  //is the word choosen
      /**************not using repeated words*****************/
      size_t NumOfCateg = 0;
      size_t NumOfWords = 1;
      NumOfWords--;
      if (cats != NULL) {
        for (size_t i = 0; i < cats->n; i++) {
          if (!strcmp(cats->arr[i].name, getcateg)) {
            NumOfCateg = i;
          }
        }
        for (size_t i = 0; i < cats->arr[NumOfCateg].n_words; i++) {
          if (!strcmp(cats->arr[NumOfCateg].words[i], cat1)) {
            NumOfWords = i;
          }
        }
      }

      if (flag_n == 1) {
        char * miduseChange = NULL;
        miduseChange = cats->arr[NumOfCateg].words[NumOfWords];
        cats->arr[NumOfCateg].words[NumOfWords] =
            cats->arr[NumOfCateg].words[cats->arr[NumOfCateg].n_words - 1];
        cats->arr[NumOfCateg].words[cats->arr[NumOfCateg].n_words - 1] = NULL;
        //free(cats->arr[NumOfCateg].words[cats->arr[NumOfCateg].n_words - 1]);
        free(miduseChange);

        if (cats->arr[NumOfCateg].n_words != 1) {
          cats->arr[NumOfCateg].words = realloc(
              cats->arr[NumOfCateg].words,
              (cats->arr[NumOfCateg].n_words - 1) * sizeof(*cats->arr[NumOfCateg].words));
        }
        cats->arr[NumOfCateg].n_words--;
      }

      /**************not using repeated words*****************/
      //   char cat[20];  //number of characters of word + 1('\0')
      //size_t countcat1 = 0;

      /*while (*(cat1 + countcat1) != '\0') {
        cat[countcat1] = *(cat1 + countcat1);
        countcat1++;
      }
      cat[countcat1] = '\0';  //is the word choosen
      */

      /*******************************/
      //char * catcp = cat;

      /////////////////store used words //////////////////
      //CountUsedNum++;
      StoreUsedNum = realloc(StoreUsedNum, CountUsedNum * sizeof(*StoreUsedNum));
      StoreUsedNum[CountUsedNum - 1] = malloc(15 * sizeof(**StoreUsedNum));
      for (size_t s = 0; s <= countcat1; s++) {
        *(StoreUsedNum[CountUsedNum - 1] + s) = cat[s];
      }
      size_t backwordnum = 0;
      backwordnum = atoi(StoreUsedNum[CountUsedNum - 1]);
      while (backwordnum) {
        catcp = StoreUsedNum[CountUsedNum - 1 - backwordnum];
        backwordnum = atoi(StoreUsedNum[CountUsedNum - 1 - backwordnum]);
      }
    }
    else {
      StoreUsedNum = realloc(StoreUsedNum, CountUsedNum * sizeof(*StoreUsedNum));
      StoreUsedNum[CountUsedNum - 1] = malloc(15 * sizeof(**StoreUsedNum));
      for (size_t s = 0; s <= getcategi; s++) {
        *(StoreUsedNum[CountUsedNum - 1] + s) = getcateg[s];
      }
      size_t backwordnum = 0;
      backwordnum = atoi(StoreUsedNum[CountUsedNum - 1]);
      while (backwordnum) {
        catcp = StoreUsedNum[CountUsedNum - 1 - backwordnum];
        backwordnum = atoi(StoreUsedNum[CountUsedNum - 1 - backwordnum]);
      }
    }

    /////////////////store used words //////////////////
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
  //////////*free space*/////////////
  for (size_t i = 0; i < CountUsedNum; i++) {
    free(StoreUsedNum[i]);
  }
  free(StoreUsedNum);
}

void ReadAndStore(char * str, catarray_t * cats) {
  char categ[20];
  size_t countstr = 0;
  while (*(str + countstr) != ':') {
    categ[countstr] = *(str + countstr);
    countstr++;
  }
  categ[countstr] = '\0';

  countstr++;
  char word[20];
  size_t wordi = 0;
  while (*(str + countstr) != '\n') {
    word[wordi] = *(str + countstr);
    countstr++;
    wordi++;
  }
  word[wordi] = '\0';

  size_t flag_all_diff = cats->n;
  if (flag_all_diff == 0) {
    cats->n++;
    cats->arr = realloc(cats->arr, cats->n * sizeof(*(cats->arr)));
    cats->arr[cats->n - 1].name = malloc(10 * sizeof(*(cats->arr[cats->n - 1].name)));

    size_t categi = 0;
    while (categ[categi] != '\0') {
      cats->arr[cats->n - 1].name[categi] = categ[categi];
      categi++;
    }
    cats->arr[cats->n - 1].name[categi] = '\0';

    cats->arr[cats->n - 1].n_words = 1;

    cats->arr[cats->n - 1].words = malloc(1 * sizeof(*(cats->arr[cats->n - 1].words)));
    cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1] = malloc(
        15 * sizeof(*cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1]));
    for (size_t j = 0; j <= wordi; j++) {
      *(cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1] + j) = word[j];
    }
  }
  else {
    size_t flagcatsn = cats->n;
    for (size_t k = 0; k < flagcatsn; k++) {
      if (strcmp(categ, cats->arr[k].name)) {
        flag_all_diff--;
      }

      if (flag_all_diff == 0) {
        cats->n++;
        cats->arr = realloc(cats->arr, cats->n * sizeof(*(cats->arr)));
        cats->arr[cats->n - 1].name = malloc(10 * sizeof(*(cats->arr[cats->n - 1].name)));

        size_t categi = 0;
        while (categ[categi] != '\0') {
          cats->arr[cats->n - 1].name[categi] = categ[categi];
          categi++;
        }
        cats->arr[cats->n - 1].name[categi] = '\0';

        cats->arr[cats->n - 1].n_words = 1;

        cats->arr[cats->n - 1].words =
            malloc(1 * sizeof(*(cats->arr[cats->n - 1].words)));
        cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1] = malloc(
            15 *
            sizeof(*cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1]));
        for (size_t j = 0; j <= wordi; j++) {
          *(cats->arr[cats->n - 1].words[cats->arr[cats->n - 1].n_words - 1] + j) =
              word[j];
        }
      }

      if (!strcmp(categ, cats->arr[k].name)) {
        cats->arr[k].n_words++;
        cats->arr[k].words = realloc(
            cats->arr[k].words, cats->arr[k].n_words * sizeof(*(cats->arr[0].words)));
        cats->arr[k].words[cats->arr[k].n_words - 1] =
            malloc(10 * sizeof(*cats->arr[k].words[cats->arr[k].n_words - 1]));
        for (size_t j = 0; j <= wordi; j++) {
          *(cats->arr[k].words[cats->arr[k].n_words - 1] + j) = word[j];
        }
      }
    }
  }
}
