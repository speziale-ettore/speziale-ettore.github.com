
#include <stdio.h>

int main(void) {
  int num, ris, i;

  do {
    printf("Inserisci un numero positivo: ");
    scanf("%d", &num);
  } while(num <= 0);

  i = 1;
  ris = 0;

  while( i <= num) {
    ris = ris + i;
    i++;
  }

  printf("La somma dei primi %d numeri naturali e' %d\n", num, ris);

  return 0;
}
