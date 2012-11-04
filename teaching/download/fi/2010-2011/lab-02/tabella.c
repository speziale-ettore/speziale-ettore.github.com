
#include <stdio.h>

#define MAX_X 10
#define MAX_Y 10

int main(void) {
  int i, j, ris;

  i = 1;

  while(i <= MAX_X) {
    j = 1;

    while(j <= MAX_Y) {
      ris = i * j;
      printf("%d\t",ris);
      j++;
    }

    printf("\n");
    i++;
  }

  return 0;
}
