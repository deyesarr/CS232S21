/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c, v;

  printf("Enter radius (in mm):\n");
  scanf("%f", &v);
  
  r = v/24.5;
  a = PI * r * r;
  c = 2 * PI * r;
  

  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Circle's circumfrence is  %3.2f (in).\n", c );

  return 0;
}
