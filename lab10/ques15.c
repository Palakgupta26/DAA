#include <stdio.h>
void findDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
    }
    printf("Elements appearing twice: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 2 * n) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the size of the permutation: ");
    scanf("%d", &n);
    int perm[n + 3];
    for (int i = 0; i < n + 3; i++) {
        printf("Enter element: ");
        scanf("%d", &perm[i]);
    }

    findDuplicates(perm, n + 4);

    return 0;
}