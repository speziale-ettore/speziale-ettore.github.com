
#include <stdio.h>

int main(int argc, char *argv) {
  int bugs;
  int i;

  bugs = 2;

  printf("A long time ago, in a faculty far far away ...\n\n");

  printf("There was a program with %d bugs\n", bugs);
  printf("- Missing \ \n");
  printf("- Missing \\n at the end of \"printf\"");
  printf("- Something wrong with counters ;)\n\n");

  printf("Moreover, variables were not initialized\n");
  printf("-     i = %d\n", i);
  printf("- i + 1 = %d\n", i + 1);

  return 0;
}
