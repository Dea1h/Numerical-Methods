#include <math.h>
#include <stdio.h>

double function(double x) {
  return exp(-x / 2.0);
}

int main() {
  double x0 = 0;
  double tol = 1e-6;
  int max_iter = 100;
  int i  = 0;

  printf("Enter initial guess x0: ");
  if (scanf("%lf", &x0) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  printf("Iter\t     x0\t\t   f(x0)\t   x1\t   f(x1)\t     x2\n");
  printf("---------------------------------------------------------------------\n");
  while (i < max_iter) {
    double fx0 = function(x0);
    printf("%3d\t%10.4lf\t%12.4lf\n", i, x0, fx0);

    if (fabs(fx0 - x0) < tol) {
      printf("\nRoot found: %.10lf\n", fx0);
      return 0;
    }
    x0 = fx0;
    i++;
  }
}
