#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Implements the radix sort algorithm on an array of integers
 *
 * Description: It is assumed that all numbers here are 0 or greater
 * @array: Array of integers
 * @size: Length of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i, divisor = 1;
	int  **queues, max_num;

	if (!array || size < 2)
		return;

	/* Create a queue to hold digits of each number */
	queues = create_queue();
	if (!queues)
		return;

	/* Allocate memory for each queue */
	if (!allocate_to_each_queue(queues, size))
		return;

	/* Find the maximum number in the array */
	max_num = find_max(array, size);

	/* Loop through each digit of the maximum number */
	while (max_num / divisor > 0)
	{
		/* perform the sort starting at least significant digit */
		lsd_sort(queues, array, size, divisor);

		print_array(array, size);

		/* move to higher significant place */
		divisor *= 10;
	}

	/* Free allocated memory */
	for (i = 0; i < 10; i++)
		free(queues[i]);
	free(queues);
}

/**
 * create_queue - Allocate memory for an array of pointers to ints
 * Return: A pointer to the array of int pointers, or NULL if failed
 */
int **create_queue(void)
{
	return (malloc(sizeof(int *) * 10));
}

/**
 * allocate_to_each_queue - Allocates memory to hold values in each queue
 * @queues: Array of queues
 * @size: Size of the array of integers to be sorted
 *
 * Return: 0 if failed, 1 otherwise
 */
int allocate_to_each_queue(int **queues, size_t size)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		queues[i] = malloc(sizeof(int) * size);
		if (!queues[i])
		{
			for (j = 0; j < i; j++)
				free(queues[j]);

			free(queues);
			return (0);
		}
	}

	return (1);
}

/**
 * find_max - Find the maximum integer in an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: The maximum integer in the array
 */
int find_max(int *array, size_t size)
{
	int    max = 0;
	size_t i   = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * lsd_sort - Performs the radix sort starting at the least significant digit
 * @queues: Array of queues
 * @array: Array of integers to be sorted
 * @size: Size of the @array
 * @divisor: The divisor to calculate the current significant digit
 */
void lsd_sort(int **queues, int *array, size_t size, int divisor)
{
	size_t row, column, array_idx;
	int    digit;

	/* Initialize queue bytes to 0 */
	for (row = 0; row < 10; row++)
		for (column = 0; column < size; column++)
			queues[row][column] = 0;

	/* Sort the numbers into their respective queues */
	/* queues are created by adding number successively which have thesame */
	/* significant digit to an array whose index corresponds to that digit */
	for (column = 0, array_idx = 0; column < size; column++, array_idx++)
	{
		digit		      = (array[array_idx] / divisor) % 10;
		queues[digit][column] = array[array_idx];
	}

	/* Rebuild the array in sorted order */
	for (array_idx = 0, row = 0; row < 10; row++)
		for (column = 0; column < size; column++)
			if (queues[row][column])
				array[array_idx++] = queues[row][column];
}
