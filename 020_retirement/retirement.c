#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
} retire_info;

void helpprint(int months,
               int startAge,
               double initial,
               double rate,
               double contribution) {
  for (int i = 1; i <= months; i++) {
    printf("Age %3d month %2d you have $%.21f\n", startAge / 12, startAge % 12, initial);
    initial += initial * rate / 12 + contribution;
    startAge += 1;
  }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  helpprint(
      working.months, startAge, initial, working.rate_of_return, working.contribution);
  startAge += working.months;
  helpprint(
      retired.months, startAge, initial, retired.rate_of_return, retired.contribution);
}

int main() {
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
}
