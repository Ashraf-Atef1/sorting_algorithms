#include "sort.h"

/**
 * selection_sort - Sorting an array with a selection_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, value;
	int tmp, swaped = 1;

	for (i = 0; swaped && i < size; i++)
	{
		value = i;
		for (j = i; j < size; j++)
		{
			if (array[value] > array[j])
				value = j;
		}
		if (value != i)
		{
			tmp = array[i];
			array[i] = array[value];
			array[value] = tmp;
			print_array(array, size);
		}
	}
}
