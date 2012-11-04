
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 3
#define MAX_WORDS 10
#define MAX_CHAR_PER_WORD 20

int main(int argc, char *argv[]) {
  char matches[MAX_CHAR][MAX_WORDS][MAX_CHAR_PER_WORD],
       tmpWord[MAX_CHAR_PER_WORD],
       chars[MAX_CHAR];

  int positions[MAX_CHAR];
  int i,j;
  int charIndex;
  int found;

  FILE *fin;

  /* Initialization */
  for(i = 0; i < MAX_CHAR; i++) {
    positions[i] = 0;
  }

  for( i = 0; i < MAX_CHAR; i++) {
    printf("Digitare un carattere: ");
    scanf("%c%*c", &chars[i]);
  }

  fin = fopen("words.dat", "r");
  if(fin != NULL) {
    fscanf(fin, "%s", tmpWord);

    while(!feof(fin)) {
      found = 0;
      for(i = 0; i < MAX_CHAR; i++) {
        /* The first character is one of those we are looking for */
        if(chars[i] == tmpWord[0]) {
          charIndex = i;
          found = 1;
           break;
        }
      }

      if(found) {
        if(positions[charIndex] < MAX_WORDS) {
          strncpy(matches[charIndex][positions[charIndex]],
                  tmpWord,
                  strlen(tmpWord) + 1);
          positions[charIndex]++;
        }
      }

      fscanf(fin, "%s", tmpWord);
    }

  } else {
    printf("Impossibile aprire il file specificato");

    return 1;
  }

  printf("Output:\n");
  for(i = MAX_CHAR - 1; i >= 0; i--) {
    for(j = positions[i]; j > 0; j--) {
      printf("%s ", matches[i][j-1]);
    }
  }

  return 0;
}
