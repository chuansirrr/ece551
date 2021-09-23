#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //WRITE ME!
  if (str == NULL) {
    return;
  }

  int length = 0;
  while (*str != '\0') {
    length += 1;
    str = str + 1;
  }

  char str_reverse[length];

  for (int i = 0; i < length; i++) {
    str = str - 1;
    str_reverse[i] = *str;
  }

  for (int j = 0; j < length; j++) {
    str[j] = str_reverse[j];
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may "
                "be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
