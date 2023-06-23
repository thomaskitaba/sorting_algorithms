#include "sort.h"
/**
* swap_ints - bubble sort
* @array: array
* @size: size  of array
*/

void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * shell_sort - shell sort algorithm
 * @array: array
 * @size: size
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;

if (array == NULL || size < 2)
return;

for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;

for (; gap >= 1; gap /= 3)
{
for (i = gap; i < size; i++)
{
j = i;
while (j >= gap && array[j - gap] > array[j])
{
swap_ints(array + j, array + (j - gap));
j -= gap;
}
}
print_array(array, size);
}
}
