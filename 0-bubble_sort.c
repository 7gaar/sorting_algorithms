#include "sort.h"

/**
 * bubble_sort - a function that use bubble sort.
 * @array: array to be sorted.
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int tmp, swap;
	size_t i, j;

	if (size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		swap = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (!swap)
			break;
	}
}
