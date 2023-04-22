#include "sort.h"
/**
* selection_sort - sorts an array of integers using selection sort
* @array: an array of integers
* @size: size of the array
*
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	int min, temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
