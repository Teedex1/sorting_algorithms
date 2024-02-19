#include "sort.h"
/**
 * selection_sort - sorts an array of int
 * @array: The array of int
 * @size: The size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	if (array == NULL || size < 2)
	       return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
