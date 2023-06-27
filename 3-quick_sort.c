#include "sort.h"

/**
 * division - division one
 * @array: array of int
 * @low: start value to compare
 * @high: highest start value to compare
 * @size: size of the array
 * Return: point of convergence between low and high
 */
size_t division(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp, pivot;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			--j;
		} while (array[j] > pivot);
		do {
			++i;
		} while (array[i] < pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		else
		{
			return (i);
		}
	}
}


/**
 * division_2 - partition two
 * @array: array of int
 * @low: lowest start value to compare
 * @high: highest start value to compare
 * @size: the size of the array
 * Return: point of convergence between low and high
 */
size_t division_2(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp;

	i = low - 1;
	j = high;

	while (1)
	{
		while (array[++i] < array[high])
		{
			if (i >= high)
				break;
		}
		while (array[--j] > array[high])
		{
			if (j <= low)
				break;
		}
		if (i >= j)
			break;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	if (i != high)
	{
		temp = array[high];
		array[high] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * qs_recn - quick sort main function
 * @array: array of int
 * @low: lower index
 * @high: higher index
 * @size: the size of the array
 */
void qs_recn(int *array, size_t low, size_t high, size_t size)
{
	size_t d;

	if (high <= low)
		return;
	d = division(array, low, high, size);
	if (d > 0)
		qs_recn(array, low, d - 1, size);
	qs_recn(array, d, high, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * @array: array of the int
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	qs_recn(array, 0, size - 1, size);
}
