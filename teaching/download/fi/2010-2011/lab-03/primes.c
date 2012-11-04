
#include <stdio.h>

#define FALSE 0
#define TRUE 1

/**
 * Checks if a number is prime
 */
int main(int argc, char* argv[]) {
  int current, prime, factor_found;

  printf("Inserire un numero: ");
  scanf("%d", &prime);

  factor_found = FALSE;
  current = 2;
  while(current <= prime / 2 && factor_found != TRUE) {
    if(prime % current == 0)
      factor_found = TRUE;
    current++;
  }

  if(factor_found == TRUE)
    printf("%d non è primo\n", prime);
  else
    printf("%d è primo\n", prime);

  return 0;
}
