#include <stdio.h>
#include <omp.h>

void merge(int a[], int l, int m, int r) {
    int temp[100], i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l; i <= r; i++) a[i] = temp[i];
}

void sort(int a[], int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    sort(a, l, m);
    sort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int a[] = {8, 3, 6, 2, 7, 1, 5, 4};
    int n = 8, m = n / 2;

    #pragma omp parallel sections
    {
        #pragma omp section
        sort(a, 0, m - 1);

        #pragma omp section
        sort(a, m, n - 1);
    }

    merge(a, 0, m - 1, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\\n");
    return 0;
}
