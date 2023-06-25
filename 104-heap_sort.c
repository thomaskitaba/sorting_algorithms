#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - swap_ints
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * max_heapify - max_heapify
 * @array: array
 * @size: size
 * @base: base row index
 * @root: root node of the BT
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;

left = 2 * root + 1;
right = 2 * root + 2;
large = root;

if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;

if (large != root)
{
swap_ints(array + root, array + large);
print_array(array, size);
max_heapify(array, size, base, large);
}
}

/**
 * heap_sort - heap_sort
 * @array: array
 * @size: size
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
max_heapify(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_ints(array, array + i);
print_array(array, size);
max_heapify(array, size, i, 0);
}
}
