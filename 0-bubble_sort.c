#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: integer array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
size_t i = 0;
while (i < size - 1)
{
	size_t j = 1;
	int change = 0;

	while (j < size - i)
	{
		if (array[j - 1] > array[j])
	{
		int temp = array[j - 1];

		array[j - 1] = array[j];
		array[j] = temp;

		print_array(array, size);
		++change;
	}
	++j;
	}
	if (!change)
		break;
	++i;
}
}
