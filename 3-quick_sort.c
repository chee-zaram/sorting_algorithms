#include "sort.h"

/**
 * quick_sort - Implementation of quick sort algorithm using an array of ints
 * @array: Array of ints
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	quick_sort_lomuto(array, size, 0, size - 1);
}

/**
 * quick_sort_lomuto - Sorts an array of ints in ascending order
 * @array: Array of ints
 * @size: Size of the array
 * @left: Index of left-most int in the sub-array
 * @right: Index of the right-most int in the sub-array
 *
 * Description: The function uses quick sort algorithm, with the Lomuto
 * Partition Scheme.
 */
void quick_sort_lomuto(int *array, size_t size, ssize_t left, ssize_t right)
{
	int swap;
	ssize_t left_clone = left;
	quick_sort_struct utils;

	utils.array = array;
	utils.curr_int_idx = left;
	utils.left = left;
	utils.right = right;
	utils.pivot_idx = &left_clone;
	utils.size = size;
	utils.pivot = array[right];

	if (left < right)
	{
		find_and_move_lesser_numbers(&utils);

		if (*utils.pivot_idx != right)
		{
			swap = array[*utils.pivot_idx];
			array[*utils.pivot_idx] = array[right];
			array[right] = swap;
			print_array(array, size);
		}

		quick_sort_lomuto(array, size, left, *utils.pivot_idx - 1);
		quick_sort_lomuto(array, size, *utils.pivot_idx + 1, right);
	}
}

/**
 * find_and_move_lesser_numbers - Finds numbers lesser than the pivot
 * @utils: Address of the struct containing data needed for finding and moving
 *
 * Description: Calls a function to move any lesser number if found
 */
void find_and_move_lesser_numbers(quick_sort_struct *utils)
{
	ssize_t i = utils->curr_int_idx;

	while (i < utils->right)
	{
		if (utils->array[i] < utils->pivot)
		{
			swap_numbers(utils, i);
			(*utils->pivot_idx)++;
		}
		i++;
	}
}

/**
 * swap_numbers - Swaps two numbers in the array of integers
 * @utils: Address of struct containing necessery data to be used for swapping
 * @i: Current index of the number to be swapped in the array
 */
void swap_numbers(quick_sort_struct *utils, ssize_t i)
{
	int swap;

	if (i != *utils->pivot_idx)
	{
		swap = utils->array[*utils->pivot_idx];
		utils->array[*utils->pivot_idx] = utils->array[i];
		utils->array[i] = swap;
		print_array(utils->array, utils->size);
	}
}
