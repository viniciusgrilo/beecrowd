#include <stdio.h>

int
main ()
{
  int speed, temp;
  float total, dist;

  scanf ("%d", &temp);
  scanf ("%d", &speed);
  
  dist = (speed * temp);
  total =  dist/ 12;

  printf ("%.3f", total);
  printf ("\n");
  return 0;
}
