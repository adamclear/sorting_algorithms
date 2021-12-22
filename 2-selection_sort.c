#include "sort.h"

/**
 * selection_sort - Sorts an integer array into ascending order
 * @array: The integer array to sort
 * @size: The size of the array, aka sizeof(array)/sizeof(int)
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t this_min_pos, swap_this, set_min_pos;
	int temp;

	if (!array || !size)
		return;

	for (swap_this = 0; swap_this < size - 1; swap_this++)
	{
		set_min_pos = swap_this;
		this_min_pos = swap_this + 1;
		for (; this_min_pos < size; this_min_pos++)
			if (array[this_min_pos] < array[set_min_pos])
				set_min_pos = this_min_pos;
		if (set_min_pos != swap_this)
		{
			temp = array[swap_this];
			array[swap_this] = array[set_min_pos];
			array[set_min_pos] = temp;
			print_array(array, size);
		}
	}
}
