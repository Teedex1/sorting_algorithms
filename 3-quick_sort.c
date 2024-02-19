#include "sort.h"
/**
 * swap_items - Swaps two items in an aray
 * @array: The array to modify
 * @l: The index of the left item.
 * @r: The index of the right item
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * lomuto_partition - Lomuto partition scheme implemation
 * @array: The array to partition
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_items(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap_items(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort_lomuto - Qicksort algorithm using lomuto's partition
 * @array: The array to sort
 * @low: The starting index of array
 * @high: The ending index
 * @size: The size of array
 */
void quicksort_lomuto(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		quicksort_lomuto(array, low, pi - 1, size);
		quicksort_lomuto(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integer
 * @array: The array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		quicksort_lomuto(array, 0, size - 1, size);
	}
}
