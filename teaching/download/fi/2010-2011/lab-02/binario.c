
#include <stdio.h>

int main(void) {
  int num, ris;

  printf("Inserisci un numero: ");
  scanf("%d", &num);

  printf("Il numero in binario, leggibile da destra verso sinistra e': ");

  do {
    ris = num % 2;
    num = num / 2;
    printf("%d", ris);
  } while(num != 0);  

  printf("\n");

  return 0;
}
