#include <stdio.h>

#define INPUT_FILE "message.dat"
#define OUTPUT_FILE "decoded.txt"

/**
 * Decode some integers from a BLOB.
 */
int main(int argc, char* argv[]) {
  FILE* input, *output;
  int buffer;

  input = fopen(INPUT_FILE, "rb");
  output = fopen(OUTPUT_FILE, "w");

  if(input != NULL) {
    if(output != NULL) {
      fread(&buffer, sizeof(int), 1, input);
      while(!feof(input)) {
          fprintf(output, "%d ", buffer);
          fread(&buffer, sizeof(int), 1, input);
      }
      fprintf(output, "\n");
      fclose(output);
    } else
    printf("Error while writing %s\n", OUTPUT_FILE);
 
    fclose(input);
  } else {
    printf("Error while opening %s\n", INPUT_FILE);
  }

  return 0; 
}
