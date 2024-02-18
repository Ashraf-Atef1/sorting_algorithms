#include "sort.h"

/**
 * counting_sort - Sorting an array with a counting_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count_array, *sorted_array, max = 0, tmp;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = (int *)calloc(sizeof(int), max + 1);
	sorted_array = (int *)calloc(sizeof(int), size);
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];
	for (i = 0; i < size; i++)
		tmp = array[i], sorted_array[count_array[tmp]] = tmp, count_array[tmp]--;
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	print_array(count_array, max + 1);
	free(count_array), free(sorted_array);
}
