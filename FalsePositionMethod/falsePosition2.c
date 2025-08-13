#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

// Function f(x) = x * x * sin(x) + exp(-x)- 3
double f(double x) {
    double radians = x * (PI / 180.0);  // Convert degrees to radians
    return x * x * sin(radians) + exp(-x) - 3;
}

int main() {
    double a, b, a1, b1, mid, fmid;
    double tolerance;
    int n = 1, max_iter = 1000; // safety limit

    // Input lower bound a
    printf("Enter lower bound a: ");
    scanf("%lf", &a);
    a1 = f(a);

    // Input upper bound b
    printf("Enter upper bound b: ");
    scanf("%lf", &b);
    b1 = f(b);

    // Input decimal precision
    printf("Enter required decimal precision (e.g., 0.001 for 3 decimal places): ");
    scanf("%lf", &tolerance);

    // Check if root lies between a and b
    if (a1 * b1 >= 0) {
        printf("The root is not bracketed between %.5lf and %.5lf\n", a, b);
        return 0;
    }

    printf("\nIteration\ta\t\tb\t\tmid\t\tf(mid)\n");
    printf("----------------------------------------------------------------------\n");

    while (fabs(b - a) >= tolerance && fabs(f(a1)) > tolerance && n <= max_iter) {
        mid = a - (a1 * (b - a)) / (b1 - a1);
        fmid = f(mid);

        printf("%d\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", n, a, b, mid, fmid);

        if (fabs(fmid) <= tolerance) { // root found within tolerance
            break;
        }

        if (a1 * fmid < 0) {
            b = mid;
            b1 = fmid;
        } else {
            a = mid;
            a1 = fmid;
        }

        n++;
    }

    if (n > max_iter) {
        printf("\nStopped: Reached maximum iterations without convergence.\n");
    } else {
        printf("\nHence, the required root is %.5lf\n", mid);
    }

    return 0;
}
