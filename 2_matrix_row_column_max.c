#include <stdio.h>
#include <omp.h>

int main() {
    int a[4][4] = {
        {1, 5, 3, 8},
        {9, 2, 6, 4},
        {7, 3, 12, 5},
        {4, 10, 2, 6}
    };
    int i, j, max;

    printf("Row maximums:\\n");
    #pragma omp parallel for private(j, max)
    for (i = 0; i < 4; i++) {
        max = a[i][0];
        for (j = 1; j < 4; j++)
            if (a[i][j] > max) max = a[i][j];

        #pragma omp critical
        printf("Row %d: %d\\n", i + 1, max);
    }

    printf("Column maximums:\\n");
    #pragma omp parallel for private(i, max)
    for (j = 0; j < 4; j++) {
        max = a[0][j];
        for (i = 1; i < 4; i++)
            if (a[i][j] > max) max = a[i][j];

        #pragma omp critical
        printf("Column %d: %d\\n", j + 1, max);
    }

    return 0;
}
