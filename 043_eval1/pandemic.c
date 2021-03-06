#include "pandemic.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

country_t parseLine(char * line) {
  //WRITE ME

  country_t ans;

  //if line has no content, error happens.
  if (line == NULL) {
    fprintf(stderr, "Line has no content in it!\n");
    exit(EXIT_FAILURE);
  }

  //if the string does not contain a comma, error happens.
  if (strchr(line, ',') == NULL) {
    fprintf(stderr, "The string has no comma, illegal!\n");
    exit(EXIT_FAILURE);
  }

  //start putting things from string into ans.
  //the string before comma is the Country name.
  size_t name_so_far = 0;  //name_so_far is the nth character of countri's name.
  while (*line != ',') {
    //if the country name is too long, more than 63 character, error happens.
    if (name_so_far >= 63) {
      fprintf(stderr, "Country name too long!\n");
      exit(EXIT_FAILURE);
    }

    ans.name[name_so_far] = *line;
    name_so_far += 1;
    line += 1;
  }
  ans.name[name_so_far] = '\0';  //add'\0' to change array to a string.

  line += 1;  //point to the next position of the first comma.

  //no population, error happens
  if (*line == '\0') {
    fprintf(stderr, "no population\n");
    exit(EXIT_FAILURE);
  }
  //if the remaining string has more comma, error happens.
  if (strchr(line, ',') != NULL) {
    fprintf(stderr, "too many commas!\n");
    exit(EXIT_FAILURE);
  }

  char * line_cp = line;  //use line_cp to flag the first number.
  //if there is no number, error happens.
  if (*line == '\n' || *line == '\0') {
    fprintf(stderr, "no number\n");
    exit(EXIT_FAILURE);
  }
  //if the number part comtains other character except number, error happens.
  while (*line != '\n' && *line != '\0') {  //'\n'or'\0'is the end of the number.
    if (!isdigit(*line)) {
      fprintf(stderr, "number is not in right format\n");
      exit(EXIT_FAILURE);
    }
    line += 1;
  }

  ans.population = atoi(line_cp);

  return ans;
}

void calcRunningAvg(unsigned * data, size_t n_days, double * avg) {
  //WRITE ME

  if (data == NULL) {
    fprintf(stderr, "no data\n");
    exit(EXIT_FAILURE);
  }

  if (n_days < 7) {
    return;
  }

  for (int i = 0; i < n_days - 6; i++) {
    avg[i] = 0;
    for (int j = i; j < i + 7; j++) {
      avg[i] = avg[i] + data[j];
    }
    avg[i] = avg[i] / 7.0;
  }
}

void calcCumulative(unsigned * data, size_t n_days, uint64_t pop, double * cum) {
  //WRITE ME
  unsigned sum = 0;

  for (int i = 0; i < n_days; i++) {
    sum = sum + data[i];
    cum[i] = (sum / (double)pop) * 100000.0;
  }
}
void printCountryWithMax(country_t * countries,
                         size_t n_countries,
                         unsigned ** data,
                         size_t n_days) {
  //WRITE ME
  char * max_country = countries[0].name;
  unsigned max_numcase = data[0][0];

  if (n_countries == 0 || n_days == 0) {
    return;
  }
  //find the max of data and the corresponding country
  int max_j = 0;
  for (int j = 0; j < n_countries; j++) {
    for (int i = 0; i < n_days; i++) {
      if (data[j][i] > max_numcase) {
        max_numcase = data[j][i];
        max_country = countries[j].name;
        max_j = j;
      }
    }
  }
  //find if there is another country that has the same max data
  for (int m = max_j + 1; m < n_countries; m++) {
    for (int n = 0; n < n_days; n++) {
      if (data[m][n] == max_numcase) {
        printf("There is a tie between at lease two countries");
        exit(EXIT_SUCCESS);
      }
    }
  }

  printf("%s has the most daily cases with %u\n", max_country, max_numcase);
  exit(EXIT_SUCCESS);
}
