#include "sort.h"

/**
 * counting_sort - A function that sorts an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int peak, i;
	int *count, *result;

	if (array == NULL || size < 2)
		return;
	peak = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > peak)
			peak = array[i];
	}
	count = malloc((peak + 1) * sizeof(int));
	if (count == NULL)
		return;
	result = malloc(size * sizeof(int));
	if (result == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < (peak + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (peak + 1); i++)
		count[i] += count[i - 1];
	print_array(count, peak + 1);
	for (i = 0; i < (int)size; i++)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = result[i];
	free(result);
	free(count);
}
