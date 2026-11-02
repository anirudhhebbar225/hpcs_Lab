#include <stdio.h>
#include <omp.h>

int main() {
    int n[] = {3, 4, 5, 6};
    int fact[4];

    #pragma omp parallel for
    for (int i = 0; i < 4; i++) {
        fact[i] = 1;
        for (int j = 1; j <= n[i]; j++)
            fact[i] *= j;
    }

    for (int i = 0; i < 4; i++)
        printf("%d! = %d\\n", n[i], fact[i]);

    return 0;
}
