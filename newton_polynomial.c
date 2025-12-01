#include <stdio.h>
#include <math.h>

int main() {
  double x = -2.5;
  double x1 = 0;
  double p0 = 0;
  double p1 = 0;
  double t = 0;
  double tol = 1e-4;
  int max_iter = 5;
  int i  = 0;

  while (i < max_iter) {
    double a = 0;
    double b = 1;
    double c = 3;
    double d = 0;
    double e = -3;
    printf("%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t\n",x,a,b,c,d,e);
    t = (a * x);
    printf("\t\t\t\t%.3lf",t);
    b = t + b;
    t = (b * x);
    printf("\t\t%.3lf",t);
    c = c + t;
    t = (c * x);
    printf("\t\t%.3lf",t);
    d = d + t;
    t = (d * x);
    printf("\t\t%.3lf\n",t);
    e = e + t;
    printf("__________________________________________________________________________\n");
    printf("\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t\n",a,b,c,d,e);
    t = (a * x);
    printf("\t\t\t\t%.3lf",t);
    b = t + b;
    t = (b * x);
    printf("\t\t%.3lf",t);
    c = c + t;
    t = (c * x);
    printf("\t\t%.3lf\n",t);
    d = d + t;
    printf("__________________________________________________________________________\n");
    printf("\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t\n",a,b,c,d);
    printf("\n\n\n\n");
    p0 = e;
    p1 = d;
    x1 = x - (p0/p1);
    printf("x1: %.3lf\n",x1);
    if (fabs(x1 - x) < tol) {
      printf("\nRoot found: %.10lf\n", x1);
      return 0;
    }
    x = x1;
    i++;
  }
}
