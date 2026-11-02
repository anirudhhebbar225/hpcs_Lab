#include <stdio.h>
#include <omp.h>

int main() {
    long n = 1000000;
    double sum = 0.0, step = 1.0 / n;

    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < n; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    printf("Value of PI = %.6f\\n", sum * step);
    return 0;
}
