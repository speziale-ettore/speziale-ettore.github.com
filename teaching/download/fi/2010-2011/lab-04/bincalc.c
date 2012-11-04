
#include <stdio.h>

#define DIGITS 10
#define MAX_NUM 1023

int main(int argc, char *argv[]) {
  int num, tmp, i;
  int num_1[DIGITS], num_2[DIGITS], res[DIGITS];

  /* Acquisisci il primo intero */
  do {
    printf("Inserisci il primo numero intero positivo: ");
    scanf("%d", &num);

    if(num > MAX_NUM) {
      printf("Il numero inserito non è rappresentabile con %d cifre binarie. "
             "Riprova.\n", DIGITS);
      num = -1;
    }
  } while(num < 0);

  /* Converti l'intero in binario */
  i = 0;
  do
  {
    tmp = num % 2;
    num = num / 2;
    num_1[i] = tmp;
    i++;
  } while(num != 0);
  while( i < DIGITS) {
    num_1[i] = 0;
    i++;
  }

  /* Acquisisci il secondo intero */
  do {
    printf("Inserisci il secondo numero intero positivo: ");
    scanf("%d", &num);

    if(num > MAX_NUM) {
      printf("Il numero inserito non è rappresentabile con %d cifre binarie. "
             "Riprova.\n", DIGITS);
      num = -1;
    }
  } while(num < 0);

  /* Converti l'intero in binario */
  i = 0;
  do {
    tmp = num % 2;
    num = num / 2;
    num_2[i] = tmp;
    i++;
  } while(num != 0);
  while( i < DIGITS) {
    num_2[i] = 0;
    i++;
  }

  /* Esegui l'AND */
  for(i = 0; i < DIGITS; i++) {
    res[i] = num_1[i] && num_2[i];
  }

  /* Stampa il primo numero */
  for(i = DIGITS - 1; i >= 0; i--) {
    printf("%d", num_1[i]);
  }
  printf(" (primo numero)\n");

  /* Stampa il secondo numero */
  for(i = DIGITS - 1; i >= 0; i--) {
    printf("%d", num_2[i]);
  }
  printf(" (secondo numero)\n");

  /* Stampa il numero */
  for(i = DIGITS - 1; i >= 0; i--) {
    printf("%d", res[i]);
  }
  printf(" (AND)\n");

  return 0;
}
