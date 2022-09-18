#include <math.h>
#include <stdio.h>

void main() {
  double result;
  double result2;
  // result = pow(16, 25);
  result2 = pow(2, 100);
  result = fmod(result2, 5);
  printf("%lf\n", result);
  printf("%lf\n", result2);
}