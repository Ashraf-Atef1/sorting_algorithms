// C++ implementation of Radix Sort

#include <stdlib.h>
#include <stdio.h>
void swap(int *first_element, int *second_element)
{
	int tmp = *first_element;
	*first_element = *second_element;
	*second_element = tmp;
}
void compAndSwap(int a[], int i, int j, int dir)
{
	if (dir == (a[i] > a[j]))
		swap(&a[i], &a[j]);
}

/*It recursively sorts a bitonic sequence in ascending order,
  if dir = 1, and in descending order otherwise (means dir=0).
  The sequence to be sorted starts at index position low,
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		printf("%d/%d\n", cnt, 16);
		for (int i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);
		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low + k, k, dir);
	}
}

/* This function first produces a bitonic sequence by recursively
	sorting its two halves in opposite sorting orders, and then
	calls bitonicMerge to make them in the same order */
void bitonicSort(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		// sort in ascending order since dir here is 1
		bitonicSort(a, low, k, 1);

		// sort in descending order since dir here is 0
		bitonicSort(a, low + k, k, 0);

		// Will merge whole sequence in ascending order
		// since dir=1.
		bitonicMerge(a, low, cnt, dir);
	}
}

void sort(int a[], int N, int up)
{
	bitonicSort(a, 0, N, up);
}

int main()
{
	int a[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
	int N = sizeof(a) / sizeof(a[0]);

	int up = 1; // means sort in ascending order

	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	sort(a, N, up);

	printf("Sorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}