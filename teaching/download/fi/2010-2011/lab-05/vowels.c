
#include <stdio.h>

#define MAX_LENGTH 30

/**
 * Reads a string, compute masq_vowels, masquerading vowels with '#', and
 * erased_vowels, erasing vowels, and at last print them to stdout.
 */
int main(int argc, char* argv[]) {
  char input[MAX_LENGTH + 1], masq_vowels[MAX_LENGTH + 1],
       erased_vowels[MAX_LENGTH + 1], current;
  unsigned int i, j;

  gets(input);

  for(i = 0, j = 0; input[i] != '\0'; i++) {
    current = input[i];
    if(current == 'a' || current == 'e' || current == 'i' ||
       current == 'o' || current == 'u' ||
       current == 'A' || current == 'E' || current == 'I' ||
       current == 'O' || current == 'U') {
      masq_vowels[i] = '#';
    } else {
      masq_vowels[i] = current;
      erased_vowels[j] = current;
      j = j + 1;
    }
  }
  masq_vowels[i] = '\0';
  erased_vowels[j] = '\0';
  
  printf("%s -> %s -> %s\n", input, masq_vowels, erased_vowels);

  return 0;
}
