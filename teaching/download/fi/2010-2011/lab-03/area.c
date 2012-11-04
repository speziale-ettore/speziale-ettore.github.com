
#include <stdio.h>

#define PI 3.14

int main(int argc, char* argv[])
{
  float r, l, area;

  printf("Raggio del cerchio: ");
  scanf("%f",&r);
  area= PI * r * r;
  printf("Area: %5.3f \n",area);

  printf("Lato del quadrato: ");
  scanf("%f",&l);
  area = l * l;
  printf("Area: %5.3f \n",area);

  return 0;
}
