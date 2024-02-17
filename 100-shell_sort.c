#include "sort.h"

/**
 * shell_sort - Sorting an array with a shell_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, i;
	int tmp;

	if (!array)
		return;
	while (gap * 3 + 1 < size)
	{
		gap = gap * 3 + 1;
	}
	for (; gap; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
			}
		}
		print_array(array, size);
	}
}
