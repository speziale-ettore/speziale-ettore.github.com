
#include <stdio.h>

int main(int argc, char * argv[]) {
  int num;
  int max;

  max = 0;

  printf("Inserire un numero: ");
  scanf("%d", &num);
  while(num != 0) {
    if(num > max) {
      max = num;
    }

    printf("Inserire un numero: ");
    scanf("%d", &num);
  }

  printf("Il massimo numero inserito è: %d\n", max);

  return 0;
} 
