
#include <stdio.h>

#define INPUT "points.dat"

typedef struct {
  int x;
  int y;
} point_t;

/* Computes the Manhattan distance between points listed in a file */
int main(int argc, char *argv[]) {
  point_t previousPoint, currentPoint;
  int distance = 0;
  FILE *fin;

  /* Open the file */
  fin = fopen(INPUT, "r");
  if(fin != NULL){
    /* Read the first two points from the file */
    fscanf(fin, "(%d,%d)", &(currentPoint.x), &(currentPoint.y));
    printf("Read (%d,%d) from file\n", currentPoint.x, currentPoint.y);
    previousPoint = currentPoint;
    fscanf(fin, "(%d,%d)", &(currentPoint.x), &(currentPoint.y));

    while(!feof(fin)) {
      printf("Read (%d,%d) from file\n", currentPoint.x, currentPoint.y);
      distance += abs(previousPoint.x-currentPoint.x) +
                  abs(previousPoint.y-currentPoint.y);

      /* Update the distance */
      previousPoint = currentPoint;
      fscanf(fin, "(%d,%d)", &(currentPoint.x), &(currentPoint.y));
    }

    printf("The total Manhattan distance is %d\n", distance);

    fclose(fin);

  } else {
    printf("errore: file %s non aperto\n", INPUT);
  }

  return 0;
}
