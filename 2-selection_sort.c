#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	int swap;
	size_t i, j, tmp;

	if (array == NULL || size == 0)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		tmp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[tmp])
			{
				tmp = j;
			}
		}
		if (tmp != i)
		{
			swap = array[i];
			array[i] = array[tmp];
			array[tmp] = swap;
			print_array(array, size);
		}
	}
}
