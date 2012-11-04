
#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
  int n;
  int d;
} fraction_t;

int main(int argc, char* argv[]) {
  fraction_t a, b, c;

  printf("Reading the first function\n");
  printf("(Insert the numerator): ");
  scanf("%d", &a.n);
  printf("(Insert the denominator): ");
  scanf("%d", &a.d);

  printf("Reading the second function\n");
  printf("(Insert the numerator): ");
  scanf("%d", &b.n);
  printf("(Insert the denominator): ");
  scanf("%d", &b.d);

  c.n = a.n * b.d + b.n * a.d;
  c.d = a.d * b.d;

  printf("\n\nThe sum is: %d/%d", c.n, c.d);

  c.n = a.n * b.n;
  c.d = a.d * b.d;

  printf("\n\nThe product is: %d/%d", c.n, c.d);

  printf("\n");

  return 0;
}
