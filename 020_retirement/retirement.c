#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void helpprint(int months,
               int startAge,
               double initial,
               double rate,
               double contribution) {
  for (int i = 1; i <= months; i++) {
    printf("Age %3d month %2d you have $%.2f\n", startAge / 12, startAge % 12, initial);
    initial += initial * rate / 12 + contribution;
    startAge += 1;
  }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  helpprint(
      working.months, startAge, initial, working.rate_of_return, working.contribution);
  startAge += working.months;
  for (int i = 1; i <= working.months; i++) {
    initial += initial * working.rate_of_return / 12 + working.contribution;
  }
  helpprint(
      retired.months, startAge, initial, retired.rate_of_return, retired.contribution);
}

int main(void) {
  retire_info working, retired;
  int startAge = 327;
  double initial = 21345;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 4.5 / 100;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 1.0 / 100;
  retirement(startAge, initial, working, retired);
  return EXIT_SUCCESS;
}
