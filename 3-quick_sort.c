#include "sort.h"
void swap(int *x, int *y);
void quick_sort_recursion(int *array, int low, int high);
int partition(int *array, int low, int high);
/**
* swap - bubble sort
* @x: x
* @y: y
*/
void swap(int *x, int *y)
{
    int *temp;
    temp = x;
    *x = *y;
    *y = *temp;
}
/**
* quick_sort - bubble sort
* @array: array
* @size: size  of array
*/
void quick_sort(int *array, size_t size)
{
quick_sort_recursion(array, 0, (int)size - 1);
}


int partition(int arr[], int low, int high) {
    int j;
    int pivot = arr[high];
    int i = low - 1;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_recursion(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quick_sort_recursion(arr, low, pivot_index - 1);
        quick_sort_recursion(arr, pivot_index + 1, high);
    }
}
