#include "sort.h"
/**
* selection_sort - Selection sort
* @array: array
* @size: size  of array
*/

void selection_sort(int *array, size_t size)
{
	int min, swap, temp;
	size_t i, j, swap_to;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		swap = 0;
		swap_to = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				swap_to = j;
				swap = 1;
			}
		}
		if (swap == 1)
		{
			temp = array[i];
			array[i] = min;
			array[swap_to] = temp;
			print_array(array, size);
		}
	}
}
