
#include <stdio.h>

#define MAX_WORD_LENGTH 50

#define INPUT_FILE "word-input.txt"
#define OUTPUT_FILE "word-output.txt"

/**
 * Reads a file, write another with mirrored words.
 */
int main(int argc, char* argv[]) {
  FILE* input, *output;
  char word[MAX_WORD_LENGTH + 1], rword[MAX_WORD_LENGTH + 1];
  unsigned int word_end, i;

  input = fopen(INPUT_FILE, "r");
  if (input != NULL){
    output = fopen(OUTPUT_FILE, "w");
    if (output != NULL){
     fscanf(input, "%s", &word);
      while(feof(input) == 0) {
        /* calcola la lunghezza della parola */
        for(i = 0; i < MAX_WORD_LENGTH; i++)
          if(word[i] == '\0') {
            word_end = i;
            break;
          }
        /* inverte la parola */
        for(i = 0; i < word_end; i++)
          rword[i] = word[word_end - 1 - i];
        rword[word_end] = '\0';
        /* scrive la parola nel nuovo file */
        fprintf(output, "%s ", rword);
        fscanf(input, "%s", &word);
      }
      fprintf(output, "\n");
       
      fclose(output);
    }
    else
      printf("Error while opening %s\n", OUTPUT_FILE);
    fclose(input);  
  }
  else
    printf("Error while opening %s\n", INPUT_FILE);
    
  return 0;
}
