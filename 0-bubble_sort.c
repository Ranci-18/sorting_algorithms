#include "sort.h"
/**
* bubble_sort - sorts an array of integers to ascending order
* @array: an array of numbers
* @size: size of array
*
* Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	int i, temp, n = size;
	bool swapped;

	if (size < 2)
		return;
	do {
		swapped = false;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		n--;
	} while
		(swapped);
}
