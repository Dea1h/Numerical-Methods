#include <stdio.h>
#include <math.h>

double function(double x) {
    // Choose the function you want:
    // double e = M_E;
    return log(x) - cos(x);
    // return 2*x + 3*cos(x) - exp(x);           // Example 2
}

const char* sign(double x) {
    return (x > 0) ? "+ve" : (x < 0) ? "-ve" : "0";
}

int main() {
    double a = 1.0;           // interval start
    double b = 1.5;           // interval end
    double tolerance = 1e-5;  // 5 decimal place accuracy

    double fa, fb, c, fc;
    int i = 1;

    fa = function(a);
    fb = function(b);

    if (fa * fb > 0) {
        printf("Error: No sign change in [%.3lf, %.3lf]\n", a, b);
        return 1;
    }

    printf("Iter\t     a\t    f(a)\t     b\t    f(b)\t     c\t    f(c)\n");
    printf("---------------------------------------------------------------------\n");

    while ((b - a) > tolerance) {
        c = (a + b) / 2.0;
        fc = function(c);

        printf("\x1b[92m%3d\t%.5lf\t%4s\t%.5lf\t%4s\t%.5lf\t%4s\n",
               i, a, sign(fa), b, sign(fb), c, sign(fc));

        // Bisection step
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        i++;
    }

    double root = (a + b) / 2.0;
    printf("\nRoot ≈ %.5lf\n", root);
    return 0;
}
