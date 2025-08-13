#include <stdio.h>
#include <math.h>

// Function f(x) = x^3 - 2x - 5
double f(double x) {
    return (x * x * x) - (2 * x) - 5;
}

int main() {
    double x1, x2, mid, fmid;
    double tolerance;
    int n = 1,max_iter = 1000;

    // Input lower and upper bounds
    printf("Enter lower bound x1: ");
    scanf("%lf", &x1);
    printf("Enter upper bound x2: ");
    scanf("%lf", &x2);

    // Input decimal precision (e.g, 0.001 for 3 decimal places)
    printf("Enter required decimal precision (e.g., 0.001 for 3 decimal places): ");
    scanf("%lf", &tolerance);

    // Check if root lies between x1 and x2
    if (f(x1) * f(x2) >= 0) {
        printf("The root is not bracketed between %.5lf and %.5lf\n", x1, x2);
        return 0;
    }

    printf("\nIteration\tx1\t\tx2\t\tmid\t\tf(mid)\n");
    printf("----------------------------------------------------------------------\n");

    while ((x2 - x1) >= tolerance && n <= max_iter) {
        mid = (x1 + x2) / 2.0;
        fmid = f(mid);

        printf("%d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", n, x1, x2, mid, fmid);

        if (f(x1) * fmid < 0) {
            x2 = mid;
        } else {
            x1 = mid;
        }

        n++;
    }

    printf("\nHence, the required root is %.5lf\n", mid);
    return 0;
}