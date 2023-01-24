#include "sort.h"

/**
 * swap - Swaps the integers are two indices
 * @array: Array of integers
 * @idx_1: Index of first integer
 * @idx_2: Index of second integer
 */
void swap(int *array, size_t idx_1, size_t idx_2)
{
	int temp;

	temp = array[idx_1];
	array[idx_1] = array[idx_2];
	array[idx_2] = temp;
}

/**
 * heapify - Arrange an array of integers in a heap data structure
 * @array: Array containing integers
 * @or_size: Original size of the array
 * @work_size: Current working size of the array
 * @parent: Parent of the integer at the last index in the current working size
 */
void heapify(int *array, size_t or_size, size_t work_size, int parent)
{
	size_t left_child = (2 * parent) + 1;
	size_t right_child = (2 * parent) + 2;
	int prev_parent = parent;

	if (VALID_RIGHT_CHILD_GREATER_THAN_PARENT)
		parent = right_child;

	if (VALID_LEFT_CHILD_GREATER_THAN_PARENT)
		parent = left_child;

	if (parent != prev_parent)
	{
		swap(array, parent, prev_parent);
		print_array(array, or_size);
	}

	if (ROOT_OR_FIRST_CHILD_OF_ROOT_AND_SWAPPED)
		heapify(array, or_size, work_size, ((work_size - 1) - 1) / 2);
	else if (prev_parent >= 0)
		heapify(array, or_size, work_size, prev_parent - 1);
}

/**
 * extract_and_insert - Extracts the max integer and inserts at the last index
 * @array: The array of integers
 * @or_size: Original size of the array
 * @max_idx: The highest index in the array
 */
void extract_and_insert(int *array, size_t or_size, size_t max_idx)
{
	int last_parent;

	if (max_idx == 0)
		return;

	max_idx = max_idx - 1;
	last_parent = ((max_idx - 1) - 1) / 2;

	if (max_idx != 0)
		swap(array, 0, max_idx), print_array(array, or_size);

	heapify(array, or_size, max_idx, last_parent);
	extract_and_insert(array, or_size, max_idx);
}

/**
 * heap_sort - Implements the heap sort algorithm
 * @array: An array of integers
 * @size: The size of the @array
 */
void heap_sort(int *array, size_t size)
{
	size_t or_size = size;
	size_t work_size = size;
	int last_parent;

	if (!array || size < 2)
		return;

	last_parent = ((size - 1) - 1) / 2;

	heapify(array, or_size, work_size, last_parent);
	extract_and_insert(array, or_size, work_size);
}
