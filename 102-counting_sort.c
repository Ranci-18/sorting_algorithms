#include "sort.h"
/**
 *counting_sort - sorts array of ints in ascending
 *@array: array of ints
 *@size: number of integers
 *
 *Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *output_arr, k;
	size_t j;

	k = largest_int(array, size);
	count_arr = (int *)malloc(sizeof(int) * (k + 1));
	if (!count_arr)
	{
		return;
	}
	init_count_inst(array, count_arr, size, k);
	sum_ints(count_arr, k);
	print_array(count_arr, k + 1);

	/*create mem space for output array as size of input array*/
	output_arr = (int *)malloc(sizeof(int) * size);
	if (!output_arr)
	{
		free(count_arr);
		return;
	}
	fill_output_arr(array, output_arr, count_arr, size);

	/*replacing the sorted values in input array*/
	for (j = 0; j < size; j++)
	{
		array[j] = output_arr[j];
	}

	free(count_arr);
	free(output_arr);
}

/**
 *largest_int - finds the largest int in the input array
 *@array: array
 *@size: size of array
 *
 *Return: largest int
 */
int largest_int(int *array, size_t size)
{
	size_t j;
	int k = array[0];

	/* find the largest integer in the input array */
	for (j = 1; j < size; j++)
	{
		if (array[j] > k)
		{
			k = array[j];
		}
	}
	return (k);
}

/**
 *init_count_inst - initializes and counts instances
 *@array: array
 *@count_arr: counting array
 *@size: size
 *@k: largest int
 *Return: no return
 */
void init_count_inst(int *array, int *count_arr, size_t size, int k)
{
	int i;
	size_t j;

	/*create mem space for counting array as the size of largest int*/
	/*initialize the array with zeros*/
	for (i = 0; i < k + 1; i++)
	{
		count_arr[i] = 0;
	}

	/*counting the instances of numbers in input array*/
	for (j = 0; j < size; j++)
	{
		count_arr[array[j]]++;
	}
}
/**
 *sum_ints - adds two corresponding ints in counting array
 *@count_arr: couting array
 *@k: largest int
 *
 *Return: no return
 */
void sum_ints(int *count_arr, int k)
{
	int i;

	/*find the sum of two pair ints*/
	for (i = 1; i <= k; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}
}

/**
 *fill_output_arr - populates output array with sorted ints
 *@array: array
 *@output_arr: output array
 *@count_arr: counting array
 *@size: size of input array
 *
 *Return: no return
 */
void fill_output_arr(int *array, int *output_arr, int *count_arr, size_t size)
{
	size_t j;

	for (j = 0; j < size; j++)
	{
		output_arr[count_arr[array[j]] - 1] = array[j];
		count_arr[array[j]]--;
	}
}
