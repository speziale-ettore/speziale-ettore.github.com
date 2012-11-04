
#include <stdio.h>

/*
 * Read two numbers from the command line ad compute modulus, integer division
 * and float division.
 */
int main(int argc, char* argv[]) {
  int ifirst, isecond, mod, idiv;
  float ffirst, fsecond, fdiv;

  printf("Insert an integer number: ");
  scanf("%d", &ifirst);
  printf("Insert another integer number: ");
  scanf("%d", &isecond);
  ffirst = (float) ifirst;
  fsecond = (float) isecond;

  mod = ifirst % isecond;
  idiv = ifirst / isecond;
  fdiv = ffirst / fsecond;

  printf("%d modulus %d = %d\n", ifirst, isecond, mod);
  printf("%d intdiv %d = %d\n", ifirst, isecond, idiv);
  printf("%f floatdiv %f = %f\n", ffirst, fsecond, fdiv);

  return 0;
}
