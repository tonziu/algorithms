#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main(void) {
    int arr[] = {6, 5, 4, 3, 2, 1};
    int len = 6;

    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j = j - 1;
        }
    }

    printf("Sorted array: [");
    for (int i = 0; i < len; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
    return 0;
}
