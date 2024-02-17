#include "sort.h"

void quick_sort_rec(int *array, size_t size, int start, int end);

/**
 * quick_sort - Sorting an array with a quick_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, size, 0, (int)size - 1);
}
/**
 * swap - Swap two elemnts in an array the print the updated array.
 * @array: An array to be sorted
 * @size: The size of the array
 * @first: first element index
 * @second: second element index
 * Ashraf Atef
 */
void swap(int *array, size_t size, size_t first, size_t second)
{
	int tmp;

	if (first != second)
	{
		tmp = array[first];
		array[first] = array[second];
		array[second] = tmp;
		print_array(array, size);
	}
}
/**
 * partition_sort - Dived an array into a two partitions.
 * @array: An array to be sorted
 * @size: The size of the array
 * @start: start index
 * @end: end index
 * Return: pivit index
 * Ashraf Atef
 */
int partition_sort(int *array, size_t size, int start, int end)
{
	int pivit = array[end];
	int p_index = start, i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivit)
		{
			swap(array, size, i, p_index);
			p_index++;
		}
	}
	swap(array, size, end, p_index);
	return (p_index);
}
/**
 * quick_sort_rec - Sorting an array with a quick_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * @start: start index
 * @end: end index
 * Ashraf Atef
 */
void quick_sort_rec(int *array, size_t size, int start, int end)
{
	size_t pivit;

	if (start < end)
	{
		pivit = partition_sort(array, size, start, end);
		quick_sort_rec(array, size, start, pivit - 1);
		quick_sort_rec(array, size, pivit + 1, end);
	}
}
