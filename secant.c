#include <stdio.h>
#include <math.h>

double function(double x) {
  double e = M_E;
  return log(x-1) - cos(x-1);
}

int main() {
  double x0 = 0;
  double x1 = 0;
  double tol = 1e-6;
  int max_iter = 100;
  int i  = 0;

  printf("Enter initial guess x0 and x1: ");
  if (scanf("%lf", &x0) != 1) {
    printf("Invalid input.\n");
    return 1;
  }
  if (scanf("%lf", &x1) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  printf("Iter\t     x0\t\t   f(x0)\t   x1\t   f(x1)\t     x2\n");
  printf("---------------------------------------------------------------------\n");
  while(i < max_iter) {
    double fx0 = function(x0);
    double fx1 = function(x1);

    if (fx1 - fx0 == 0.0) {
      printf("Division by zero. Cannot continue.\n");
      return 1;
    }
    double x2 = x1 - ((fx1 * (x1 - x0)) / (fx1 - fx0));

    printf("%3d\t%10.5lf\t%12.5lf\t%10.5lf\t%12.5lf\t%10.5lf\n", i, x0, fx0, x1, fx1, x2);
    if (fabs(x2 - x1) < tol) {
      printf("\nRoot found: %.10lf\n", x2);
      return 0;
    }

    x0 = x1;
    x1 = x2;
    i++;
  }
  printf("Did not converge in %d iterations.\n", max_iter);
  return 0;
}
