#include "sort.h"

void swap(int *first_element, int *second_element);
/**
 * radix_sort - Sorting an array with a radix_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void radix_sort(int *array, size_t size)
{
	int *buffer_array = malloc(sizeof(int) * size), max = 0;
	size_t i = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (i = 1; max / i != 0; i *= 10)
		;
	max = i;
	buffer_array[0] = i;
	printf("%d\n", max);
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
