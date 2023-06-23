#include "sort.h"
/**
* merge_sorted_arrays - merge_sorted_arrays
* @array: original array
* @l:  left most index
* @r: right most index
* @m: middle index
* Return: Nothing
*/
void merge_sorted_arrays(int *array, int l, int m, int r)
{
int i, j, k;
int left_length = m - l + 1;
int right_length = r - m;

int left_a[left_length];
int right_a[right_length];

for (i = 0; i < left_length; i++)
{
    left_a[i] = array[l + i];
}
for (i = 0; i < right_length; i++)
{
    right_a[i] = array[m + i + 1];
}
for (i = j = k = 0; k <= r; k++)
{
    if ((i < left_length) && (j >= right_length || left_a[i] < right_a[j]))
    {
        array[k] = left_a[i];
        i++;
    }
    else
    {
        array[k] = right_a[j];
        j++;
    }

}
}
/**
* merge_sort_recursion - merge_sort_recursion
* @array: array
* @size: size  of array
*/
void merge_sort_recursion(int *array, int l, int r)
{
/* step 1: devide the array in to half*/
    int m;
    if (l < r)
    {
        m = (l + (r - 1)) / 2;
        merge_sort_recursion(array, l, m);
        merge_sort_recursion(array, m + 1, r);

        merge_sorted_arrays(array, l, m, r);
    }
}

/**
* merge_sort - merge sort
* @array: array
* @size: size  of array
*/

void merge_sort(int *array, size_t size)
{
merge_sort_recursion(array, 0, (int)size - 1);
}
