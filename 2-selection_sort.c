#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;

	while (i < size - 1)
	{
		size_t j = i + 1;
		size_t min = i;

		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			++j;
		}

		if (min != i)
		{
			int swap_in = array[min];

			array[min] = array[i];

			array[i] = swap_in;

			print_array(array, size);
		}

		++i;
	}
}
