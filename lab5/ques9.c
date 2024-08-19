#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
struct Student {
    int roll_number;
    char name[50];
};

void merge(struct Student arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].roll_number <= R[j].roll_number) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *fp;
    int count = 0;
    char filename[MAX_FILE_NAME];
    char c;
    fp = fopen("input.txt", "r");
 
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;
 
    fclose(fp);
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    struct Student students[count];
    for (int i = 0; i < count; i++) {
        fscanf(inputFile, "%d%s", &students[i].roll_number, students[i].name);
    }

    mergeSort(students, 0, count - 1);

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d\t%s\n", students[i].roll_number, students[i].name);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
