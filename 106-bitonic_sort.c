#include "sort.h"

void bitonic_sort_spliter(int *array, size_t start, int cut_size, int dir);
void bitonic_sort_merge(int *array, size_t start, int cut_size, int dir);
void swap_with_dir(int *first, int *second, int dir);

/**
 * bitonic_sort - Sorting an array with a bitonic_sort algo.
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */

void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_spliter(array, 0, size, 1);
}

/**
 * bitonic_sort_spliter - Sorting an array with a bitonic_sort algo.
 * @array: An array to be sorted
 * @start: The start index
 * @cut_size: The split size
 * @dir: The sorting direction
 * Ashraf Atef
 */
void bitonic_sort_spliter(int *array, size_t start, int cut_size, int dir)
{
	static int array_size;
	int new_cut_size = cut_size / 2;

	if (!array_size)
		array_size = cut_size;
	if (new_cut_size < 1)
		return;

	printf("Merging [%d/%d] (%s):\n", cut_size,
		   array_size, dir > 0 ? "UP" : "DOWN");
	print_array(array + start, cut_size);

	bitonic_sort_spliter(array, start, new_cut_size, 1);
	bitonic_sort_spliter(array, start + new_cut_size, new_cut_size, 0);
	bitonic_sort_merge(array, start, cut_size, dir);

	printf("Result [%d/%d] (%s):\n", cut_size,
		   array_size, dir > 0 ? "UP" : "DOWN");
	print_array(array + start, cut_size);
}
/**
 * bitonic_sort_merge - Sorting and merge two splits size.
 * @array: An array to be sorted
 * @start: The start index
 * @cut_size: The split size
 * @dir: The sorting direction
 * Ashraf Atef
 */
void bitonic_sort_merge(int *array, size_t start, int cut_size, int dir)
{
	int steps = cut_size / 2;
	size_t i;

	if (!steps)
		return;

	for (i = start; i < start + steps; i++)
		swap_with_dir(array + i, array + i + steps, dir);

	bitonic_sort_merge(array, start, steps, dir);
	bitonic_sort_merge(array, start + steps, steps, dir);
}

/**
 * swap_with_dir - Swap two integers in an array by a direction.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 * @dir: The sort direction
 * Ashraf Atef
 */
void swap_with_dir(int *first, int *second, int dir)
{
	int tmp = *first;

	if (dir == (*first > *second))
		*first = *second, *second = tmp;
}
