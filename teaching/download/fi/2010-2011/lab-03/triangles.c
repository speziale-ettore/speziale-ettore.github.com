
#include <stdio.h>

#define FALSE 0
#define TRUE 1

/**
 * Checks some properties about a triangle
 */
int main(int argc, char* argv[]) {
  int a, b, c, check_for_rect;

  printf("Inserire tre numeri: ");
  scanf("%d %d %d", &a, &b, &c);

  if(a > b + c || b > a + c || c > a + b) {
    printf("I tre numeri non rappresentano le lunghezze dei lati di tre "
            "triangoli\n");
    check_for_rect = FALSE;
  }
  else if(a == b + c || b == a + c || c == a + b) {
    printf("Il triangolo è degenere\n");
    check_for_rect = FALSE;
  }
  else if(a == b && b == c) {
    printf("Il triangolo è equilatero\n");
    check_for_rect = FALSE;
  }
  else if(a == b || b == c || a == c) {
    printf("Il triangolo è isoscele\n");
    check_for_rect = TRUE;
  }
  else {
    printf("Il triangolo è scaleno\n");
    check_for_rect = TRUE;
  }

  if(check_for_rect)
    if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
      printf("Il triangolo è rettangolo\n");

  return 0;
}
