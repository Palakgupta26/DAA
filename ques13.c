#include <stdio.h>
#include <string.h>

void insertionSort(char arr[][50], int n) {
    int i, j;
    char key[50];
    for (i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) < 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], key);
    }
}
int main() {
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char names[n][50];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    insertionSort(names, n);
    printf("\n\nSorted Names in Descending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }
    return 0;
}
