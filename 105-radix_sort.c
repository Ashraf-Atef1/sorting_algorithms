#include "sort.h"

void swap(int *first_element, int *second_element);
void radix_sort_core(int *array, int *buffer_array, size_t size, size_t radix);
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
		radix_sort_core(array, buffer_array, size, i), print_array(array, size);

	free(buffer_array);
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
/**
 * radix_sort_core - The core function to sort an array with a radix_sort algo.
 * @array: An array to be sorted
 * @buffer_array: A buffer array to store tmp output
 * @size: The size of the array
 * @radix: The current radix number
 * Ashraf Atef
 */
void radix_sort_core(int *array, int *buffer_array, size_t size, size_t radix)
{
	int count_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i = 0;

	for (i = 0; i < size; i++)
		count_array[(array[i] / radix) % 10]++;
	for (i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];
	for (i = size - 1; i < size; i--)
		buffer_array[count_array[(array[i] / radix) % 10]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = buffer_array[i];
}
