#include "sort.h"

void swap(int *first_element, int *second_element);
void quick_sort_hoare_rec(int *array, size_t size, int start, int end);

/**
 * quick_sort_hoare - Sorting an array with a quick_sort_hoare algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_hoare_rec(array, size, 0, size);
}
/**
 * quick_sort_hoare_rec - Sorting an array with a quick_sort_hoare algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * @start: The start index of the to be sorted array
 * @end: The end index + 1 of the to be sorted array
 * Ashraf Atef
 */
void quick_sort_hoare_rec(int *array, size_t size, int start, int end)
{
	int i = start, j = end - 1, pivit = array[j];

	if (start >= end - 1)
		return;
	for (; i < j;)
	{
		while (array[i] < pivit)
			i++;
		while (array[j] > pivit)
			j--;
		if (i < j)
			swap(array + i, array + j), print_array(array, size);
	}
	quick_sort_hoare_rec(array, size, start, i);
	quick_sort_hoare_rec(array, size, i, end);
}
/**
 * swap - Swap two integers in an array.
 * @first_element: The first integer to swap.
 * @second_element: The second integer to swap.
 * Ashraf Atef
 */
void swap(int *first_element, int *second_element)
{
	int tmp = *first_element;
	*first_element = *second_element;
	*second_element = tmp;
}
