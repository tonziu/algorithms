#include <stdio.h>

void merge(int* arr, size_t p, size_t q, size_t r) {

    size_t n_left = q - p + 1;
    size_t n_right = r - q;
    
    int left[n_left];
    int right[n_right];

    for (size_t i = 0; i < n_left; i++) {
        left[i] = arr[p+i];
    }

    for (size_t i = 0; i < n_right; i++) {
        right[i] = arr[q+i+1];
    }

    size_t i = 0;
    size_t j = 0;

    size_t k = p;

    while (i < n_left && j < n_right) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n_left) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n_right) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr, size_t p, size_t r) {

    if (p >= r) 
        return;

    size_t q = (p + r) / 2;

    merge_sort(arr, p, q);
    merge_sort(arr, q+1, r);

    merge(arr, p, q, r);
}

void printf_array(int* arr, size_t len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    
    int arr[] = {5, 2, 9, 3, 1, 6, 4, 8, 7, 0};

    printf("Array to sort: ");
    printf_array(&arr[0], 10);
    
    merge_sort(&arr[0], 0, 9);

    printf("Sorted: ");
    printf_array(&arr[0], 10);

    return 0;
}
