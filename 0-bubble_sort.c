#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array
 * @array: The array of int
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, sort;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sort = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				sort = 1;
			}
		}
		if (!sort)
			break;

		print_array(array, size);
	}
}
