#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	unsigned int i, j, gap = 1;

	if (size < 2 || array == NULL)
	{
		return;
	}
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
