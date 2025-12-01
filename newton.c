#include <stdio.h>
#include <math.h>

double f(double x) {
  double e = M_E;
  return log(x-1) + cos(x-1);
}

double df(double x) {
  return 1.0/(x-1) - sin(x-1);
}

int main() {
  double x0 = 0;                   // initial guess
  double tol = 1e-6;           // desired accuracy
  int max_iter = 100;
  int i = 0;

  printf("Enter initial guess x0: ");
  if (scanf("%lf", &x0) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  printf("Iter\t     xi\t\t   f(xi)\t   f'(xi)\t     xi+1\n");
  printf("---------------------------------------------------------------------\n");

  while (i < max_iter) {
    double fx = f(x0);
    double dfx = df(x0);

    if (dfx == 0.0) {
      printf("Derivative zero. Cannot continue.\n");
      return 1;
    }

    double x1 = x0 - fx/dfx;

    printf("%3d\t%10.5lf\t%12.5lf\t%12.5lf\t%10.5lf\n", i, x0, fx, dfx, x1);

    if (fabs(x1 - x0) < tol) {
      printf("\nRoot found: %.10lf\n", x1);
      return 0;
    }

    x0 = x1;
    i++;
  }

  printf("Did not converge in %d iterations.\n", max_iter);
  return 0;
}
