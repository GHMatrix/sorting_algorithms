#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int low, int high);
void hoare_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers according to
 *                   the Hoare partition scheme (first element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
	do {
		i++;
	} while (array[i] < pivot);

	do {
		j--;
	} while (array[j] > pivot);

	if (i >= j)
		return (j);

	swap_ints(&array[i], &array[j]);
	print_array(array, size);
	}
}

/**
 * hoare_sort - function uses the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition
 * @high: The ending index of the array partition
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
	int partition_index = hoare_partition(array, size, low, high);

	hoare_sort(array, size, low, partition_index);
	hoare_sort(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using
 *              the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints the array
 *              after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	hoare_sort(array, size, 0, size - 1);
}