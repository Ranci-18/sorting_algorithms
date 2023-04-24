#include "sort.h"
/**
* shell_sort - sorts an array of numbers using shell sort method
* @array: an array of numbers
* @size: size of the array
*
* Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	int gaps[1000], count = 0, i, k, gap, temp;
	size_t n = 1, j;

	if (size < 2)
		return;
	while (n < size / 3)
	{
		gaps[count] = n;
		count++;
		n = n * 3 + 1;
	}
	gaps[count] = n;
	count++;

	for (i = count - 1; i >= 0; i--)
	{
		gap = gaps[i];
		for (j = gap; j < size; j++)
		{
			for (k = j - gap; k >= 0; k -= gap)
			{
				if (array[k + gap] > array[k])
					break;
				temp = array[k + gap];
				array[k + gap] = array[k];
				array[k] = temp;
			}
		}
		print_array(array, size);
	}
}
