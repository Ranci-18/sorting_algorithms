#include "sort.h"
/**
 *quick_sort - sorts an array of integers from smallest to largest
 *@array: array to sort
 *@size: size of array
 *
 *
 *Return: no return
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (!array || size < 2)
		return;

	quick_sort2(array, start, end, size);
}
/**
 *quick_sort2 - function sorts array of integers
 *@array: array of ints
 *@start: start of array
 *@end: end of array/last index
 *@size: size of array
 *Return: nothing
 */
void quick_sort2(int *array, int start, int end, int size)
{
	int pivot_idx;

	if (start < end)
	{
		pivot_idx = lomut_partition(array, start, end, size);
		quick_sort2(array, start, pivot_idx - 1, size);
		quick_sort2(array, pivot_idx + 1, end, size);
	}
}

/**
 *lomut_partition - partitions the main array
 *@array: the array
 *@strt: first index
 *@nd: last index
 *@size: size of array
 *Return: the index of the pivot element
 */
int lomut_partition(int *array, int strt, int nd, int size)
{
	int pivot = array[nd], p_idx = strt, j, temp;

	for (j = strt; j < nd; j++)
	{
		if (array[j] <= pivot)
		{
			if (p_idx != j)
			{
				temp = array[p_idx];
				array[p_idx] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			p_idx++;
		}
	}
	if (p_idx != nd)
	{
		temp = array[p_idx];
		array[p_idx] = array[nd];
		array[nd] = temp;
		print_array(array, size);
	}

	return (p_idx);
}
