#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *               bubble sort algorithm
 * @array: input pointer to the array of integers
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int x, y, temp;

	for (y = 0; y < (size - 1); y++)
	{
		for (x = 0; x < (size - y - 1); x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
			}
		}
	}
return;
}
