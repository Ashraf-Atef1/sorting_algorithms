#include "sort.h"

/**
 * quick_sort - Sorting an array with a quick_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void quick_sort(int *array, size_t size)
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
size_t partition_sort(int *array, size_t size, size_t start, size_t end)
{
	int pivit = array[end], tmp;
	size_t p_index = start, i;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivit)
		{
			tmp = array[i];
			array[i] = array[p_index];
			array[p_index] = tmp;
			p_index++;
			print_array(array, size);
		}
	}
	array[end] = array[p_index];
	array[p_index] = pivit;
	print_array(array, size);
	return (p_index);
}
void quick_sort_rec(int *array, size_t size, size_t start, size_t end)
{
	size_t pivit;

	if (start < end)
	{
		pivit = partition_sort(array, size, start, end);
		quick_sort_rec(array, size, start, pivit - 1);
		quick_sort_rec(array, size, pivit + 1, end);
	}
}