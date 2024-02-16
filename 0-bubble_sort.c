#include "sort.h"

/**
 * bubble_sort - Sorting an array with a bubble_sort type
 * @array: An array to be sorted
 * @size: The size of the array
 * Ashraf Atef
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swaped = 1, c_num, n_num, tmp;

	while (swaped)
	{
		swaped = 0;
		for (i = 0; i < size - 1; i++)
		{
			c_num = array[i], n_num = array[i + 1];
			if (c_num > n_num)
			{
				tmp = c_num, array[i] = n_num, array[i + 1] = tmp, swaped = 1;
				print_array(array, size);
			}
		}
	}
}
