#include "sort.h"

void heapify(int *array, size_t size, size_t i);
void swap(int *first_element, int *second_element);
void max_heapify(int *array, size_t size, size_t base, size_t root);
/**
 * heap_sort - Sorting an array with a heap_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || !size)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i);
	for (i = size - 1; i > 0; i--)
		swap(array, array + i), print_array(array, size), heapify(array, i, 0);
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
 * heapify - Turn an array into a complete binary heap.
 * @array: An array of integers.
 * @size: The size of the array.
 * @i: The root node of the binary tree.
 * Ashraf Atef
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t l_node = i * 2 + 1;
	size_t r_node = i * 2 + 2;
	size_t max = i;
	static size_t array_size;

	if (!array_size)
		array_size = size;
	if (l_node < size && array[max] < array[l_node])
		max = l_node;
	if (r_node < size && array[max] < array[r_node])
		max = r_node;
	if (max != i)
		swap(array + i, array + max),
			print_array(array, array_size), heapify(array, size, max);
}
