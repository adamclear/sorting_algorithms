#include "sort.h"
/**
 * quick_sort - uses Lomuto partition to quick sort integer array
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_2(array, 0, (size - 1), size);
}

/**
 * quicksort_2 - usess Lomuto partiton to quick sort integer array
 * @array: pointer to the array
 * @left: 0 index
 * @right: last index
 * @size: size of the array
 * Return: void
 */
void quicksort_2(int *array, int left, int right, size_t size)
{
	int i;

	if (left < right)
	{
		i = partition(array, left, right, size);
		quicksort_2(array, left, i - 1, size);
		quicksort_2(array, i + 1, right, size);
	}
}

/**
 * partition - uses Lomuto partition to quick sort integer array
 * @array: pointer to the array
 * @left: 0 index
 * @right: last index
 * @size: size of the array
 * Return: partition index
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left;
	int j, temp = 0;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (temp != array[i])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[right];
	array[right] = temp;
	if (temp != array[i])
		print_array(array, size);
	return (i);
}
