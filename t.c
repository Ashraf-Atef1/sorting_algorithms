#include "sort.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

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
	int i;
	int *buff_array;

	if (!array || !size || size == 1)
		return;

	buff_array = (int *)calloc(sizeof(int), size);
	for (i = 0; i < size; i++)
		buff_array[i] = array[i];
	printf("test1\n");
	merge_sort_rec(array, buff_array, 0, size);
	free(buff_array);
}
void merge_sort_merge(int *array, int *buff_array, int start, int mid, int end)
{
	int i, j = mid, k = start, l_size = mid - start, r_size = end - mid;

	printf("test3\n");
	printf("Merging...\n[left]: ");
	print_array(buff_array + start, l_size);
	printf("[right]: ");
	print_array(buff_array + start, r_size);
	for (i = start; i < l_size + r_size; i++)
		if (k >= mid)
			array[i] = buff_array[j++];
		else if (j >= end)
			array[i] = buff_array[k++];
		else
		{
			if (buff_array[k] < buff_array[j])
				array[i] = buff_array[k++];
			else
				array[i] = buff_array[j++];
		}
	printf("[Done]: ");
	print_array(array + start, i);
}
void merge_sort_rec(int *array, int *buff_array, int start, int end)
{
	int mid = start + (start + end) / 2;

	if (start >= end)
		return;
	merge_sort_rec(array, buff_array, start, mid);
	merge_sort_rec(array, buff_array, mid, end);
	printf("test2\n");
	merge_sort_merge(array, buff_array, start, mid, end);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	merge_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}