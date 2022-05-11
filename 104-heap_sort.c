#include "sort.h"

/**
 * heap_sort - sorts the array using the sift-down heap sort algorithm.
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int parent;
	int array_len = size;

	if (!array || size < 2)
		return;

	for (parent = ((size / 2) - 1); parent >= 0; parent--)
	{
		heapify(array, size, parent, array_len);
	}
	for (parent = (size - 1); parent >= 0; parent--)
	{
		swap(&array[0], &array[parent]);
		if (parent > 0)
			print_array(array, array_len);
		heapify(array, parent, 0, array_len);
	}
}

/**
 * heapify - finds the children of the parent and swaps if necessary.
 * @array: pointer to the array.
 * @parent: current parent node.
 * @size: size of the heap to build.
 * @array_len: size of the array.
 */
void heapify(int *array, int size, int parent, int array_len)
{
	int largest = parent;
	int lidx = 2 * parent + 1;
	int ridx = 2 * parent + 2;

	if (lidx < size && array[lidx] > array[largest])
		largest = lidx;
	if (ridx < size && array[ridx] > array[largest])
		largest = ridx;
	if (largest != parent)
	{
		swap(&array[parent], &array[largest]);
		print_array(array, array_len);
		heapify(array, size, largest, array_len);
	}
}

/**
 * swap - swaps the position of two elements.
 * @x: first element to be swapped.
 * @y: second element to be swapped.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
