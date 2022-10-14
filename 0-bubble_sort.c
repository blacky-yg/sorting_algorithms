#include "sort.h"

/**
 * my_swap - Swaps two integers in an array.
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void my_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, len = size;
	bool sort = false;

	if (!array || size < 2)
		return;

	while (!sort)
	{
		sort = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				my_swap(array + i, array + i + 1);
				print_array(array, size);
				sort = false;
			}
		}
		len--;
	}
}
