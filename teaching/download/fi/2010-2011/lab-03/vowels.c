
#include <stdio.h>

/**
 * Prints statistics about a char sequence
 */
int main(int argc, char* argv[]) {
  char current_char;
  int a_count = 0,
      e_count = 0,
      i_count = 0,
      o_count = 0,
      u_count = 0,
      char_count = 0;

  printf("Inserisci caratteri:\n");

  do {
    scanf("%c", &current_char);
    char_count++;
    if(current_char == 'a')
      a_count++;
    else if(current_char == 'e')
      e_count++;
    else if(current_char == 'i')
      i_count++;
    else if(current_char == 'o')
      o_count++;
    else if(current_char == 'u')
      u_count++;
  } while(current_char != '#');

  printf("Ho trovato %d caratteri:\n"
         "#a = %d\n"
         "#e = %d\n"
         "#i = %d\n"
         "#o = %d\n"
         "#u = %d\n",
         char_count, a_count, e_count, i_count, o_count, u_count);

  return 0;
}
