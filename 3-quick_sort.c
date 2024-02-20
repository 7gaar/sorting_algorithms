#include "sort.h"

/**
 * quick_sort - a function that sorts an array using quick sort.
 * @array: array to be sorted.
 * @size: size of an array.
*/
void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);

}

/**
 * quicksort_recursion - recursive function,
 * @array: array to be sorted.
 * @lb: lower bound.
 * @ub: upper bound.
 * @size: size of array.
*/
void quicksort_recursion(int *array, int lb, int ub, size_t size)
{
	int piv;

	if (lb < ub)
	{
		piv = partition(array, lb, ub, size);
		quicksort_recursion(array, lb, piv - 1, size);
		quicksort_recursion(array, piv + 1, ub, size);
	}
}
/**
 * partition - a function that split the array.
 * @array: array to be split.
 * @lb: lower bound.
 * @ub: upper bound.
 * @size: array size.
 * Return: returns the end value on success.
*/
int partition(int *array, int lb, int ub, size_t size)
{
	int piv_val = array[ub];
	int i = lb, j;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= piv_val)
		{
			swap_a(&array[i], &array[j]);
			i++;
		}
	}
	swap_a(&array[i], &array[ub]);
	print_array(array, size);
	return (i);
}

/**
 * swap_a - a function that swaps values.
 * @a: first value.
 * @b: second value.
*/
void swap_a(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
