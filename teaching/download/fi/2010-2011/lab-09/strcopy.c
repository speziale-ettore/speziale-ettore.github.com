
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

char *strcopy(char *origStr) {
  char *newStr;
  int length;

  length = strlen(origStr);

  newStr= (char *) malloc((length + 1) * sizeof(char));
  strcpy(newStr, origStr);

  return newStr;
}

int main(int argc, char *argv[]) {
  char tmp[MAX_LEN];
  char *newStr;

  strcpy(tmp, "Stringa di prova\n");

  newStr = strcopy(tmp);
  printf("%s", newStr);

  free(newStr);

  return 0;
}
