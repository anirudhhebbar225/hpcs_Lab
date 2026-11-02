#include <stdio.h>
#include <omp.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n = 100;
    double start, end;

    start = omp_get_wtime();
    printf("Serial primes: ");
    for (int i = 1; i <= n; i++)
        if (isPrime(i)) printf("%d ", i);
    end = omp_get_wtime();
    printf("\\nSerial time: %f seconds\\n", end - start);

    start = omp_get_wtime();
    printf("Parallel primes: ");
    #pragma omp parallel for
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            #pragma omp critical
            printf("%d ", i);
        }
    }
    end = omp_get_wtime();
    printf("\\nParallel time: %f seconds\\n", end - start);

    return 0;
}
