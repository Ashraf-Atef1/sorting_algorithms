#include "sort.h"

void merge_sort_rec(int *array, int *buff_array, int start, int end);
void merge_sort_merge(int *array, int *buff_array, int start, int mid, int end);
/**
 * merge_sort - Sorting an array with a merge_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void merge_sort(int *array, size_t size)
{
	int i, array_size = (int)size;
	int *buff_array;

	if (!array || !size || size == 1)
		return;

	buff_array = (int *)calloc(sizeof(int), size);
	for (i = 0; i < array_size; i++)
		buff_array[i] = array[i];
	merge_sort_rec(array, buff_array, 0, array_size);
	free(buff_array);
}
void merge_sort_merge(int *array, int *buff_array, int start, int mid, int end)
{
	int i, j, k, l_size = mid - start, r_size = end - mid,
				 final_size = l_size + r_size,
				 *l_array = buff_array + start, *r_array = buff_array + mid,
				 *final_array = array + start, *final_buffer = buff_array + start;

	printf("l_size:%d, r_size:%d\n", l_size, r_size);
	printf("Merging...\n[left]: ");
	print_array(l_array, l_size);
	printf("[right]: ");
	print_array(r_array, r_size);
	for (i = 0, j = 0, k = 0; j < l_size || k < r_size; i++)
	{
		if (j >= l_size)
			final_array[i] = r_array[k++];
		else if (k >= r_size)
			final_array[i] = l_array[j++];
		else if (l_array[j] < r_array[k])
			final_array[i] = l_array[j++];
		else
			final_array[i] = r_array[k++];
	}

	for (i = 0; i < final_size; i++)
		final_buffer[i] = final_array[i];
	printf("[Done]: ");
	print_array(final_array, final_size);
}
void merge_sort_rec(int *array, int *buff_array, int start, int end)
{
	int mid = start + (end - start) / 2;

	if (end - start <= 1)
		return;
	merge_sort_rec(array, buff_array, start, mid);
	merge_sort_rec(array, buff_array, mid, end);
	merge_sort_merge(array, buff_array, start, mid, end);
}
