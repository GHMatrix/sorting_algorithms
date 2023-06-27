#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: The array of integers.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	int j;

	for (j = left; j <= right - 1; j++)
	{
	if (array[j] < pivot)
	{
		i++;
	if (i != j)
	{
		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
	}
	}

	if (array[i + 1] != array[right])
	{
	swap_ints(&array[i + 1], &array[right]);
	print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Recursive function to implement
 * Quick Sort using Lomuto partition.
 * @array: The array of integers.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */
void lomuto_sort(int *array, int left, int right, size_t size)
{
	if (left < right)
	{
	int partition = lomuto_partition(array, left, right, size);

	lomuto_sort(array, left, partition - 1, size);
	lomuto_sort(array, partition + 1, right, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	lomuto_sort(array, 0, size - 1, size);
}
