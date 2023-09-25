#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one sorted array
 * @tmp: The tmp array containing two subarrays to be merged
 * @buffer: Array for sorted integers
 * @left: the start of the left subarray
 * @mid: the end of the left subarray
 * @right: the end of the right subarray
 * Return: Nothing
 */
void merge(int *tmp, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]:  ");
	print_array(tmp + left, mid - left);
	printf("[right]: ");
	print_array(tmp + mid, right - mid);
	for (i = left, j = mid; i < mid && j < right; k++)
	{
		buffer[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j++];
	}
	for (; i < mid; i++)
	{
		buffer[k++] = tmp[i];
	}
	for (; j < right; j++)
	{
		buffer[k++] = tmp[j];
	}
	for (i = left, k = 0; i < right; i++)
	{
		tmp[i] = buffer[k++];
	}
	printf("[Done]: ");
	print_array(tmp + left, right - left);
}

/**
 * merge_rec - Recursive function to merge sort an array
 * @tmp: array containing two subarrays to be merged
 * @buffer: array for sorted integers
 * @left: the start of the left subarray
 * @right: the end of the right subarray
 * Return: Nothing
 */
void merge_rec(int *tmp, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_rec(tmp, buffer, left, mid);
		merge_rec(tmp, buffer, mid, right);
		merge(tmp, buffer, left, mid, right);
	}
}
/**
 * merge_sort - A function that sorts an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
	{
		return;
	}

	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
	{
		return;
	}

	merge_rec(array, tmp, 0, size);
	free(tmp);
}
