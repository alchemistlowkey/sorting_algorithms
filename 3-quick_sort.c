#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_rec(array, 0, size - 1, size);
}

/**
 * swap - Swaps two integers in an array
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 * Return: Nothing
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * quick_rec - Recursive function for Quick sort
 * @array: The array to be partitioned
 * @lb: The starting index of the partition(lower bound)
 * @hb: The ending index of the partition(higher bound)
 * @size: size of the array
 * Return: Nothing
 */

void quick_rec(int *array, int lb, int hb, size_t size)
{
	int pivot;

	if (lb < hb)
	{
		pivot = partition(array, lb, hb, size);
		quick_rec(array, lb, pivot - 1, size);
		quick_rec(array, pivot + 1, hb, size);
	}
}

/**
 * partition - A function that partition an array
 * @array: pointer to the array
 * @low: lower bound
 * @high: higher bound
 * @size: size of the array
 * Return: i
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	i = low;
	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, size);
	return i;
}
