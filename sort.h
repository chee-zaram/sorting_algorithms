#ifndef _SORT_H_
#define _SORT_H_

#define FALSE	0
#define TRUE	1

#define CHECK_FOR_LAST_NODE	\
(!node_to_insert->next && node_to_insert->prev && node_to_insert->prev->prev)

#define CHECK_FOR_REGULAR	\
(node_to_insert->prev && node_to_insert->prev->n > node_to_insert->n)

#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct quick_sort_util - Contains data for implementing quick sort algo
 * @array: Array of ints
 * @curr_int_idx: Current index in array being analyzed
 * @left: Index of left-most number in the (sub-)array
 * @right: Index of right-most number in the sub-array
 * @pivot_idx: Address of the current pivot index
 * @size: Size of our array
 * @pivot: Current in the (sub-)array
 */
typedef struct quick_sort_util
{
	int *array;
	ssize_t curr_int_idx;
	ssize_t left;
	ssize_t right;
	ssize_t *pivot_idx;
	size_t size;
	int pivot;
} quick_sort_struct;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insertion_sort(listint_t **list, listint_t *current, listint_t *cur_prev);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_lomuto(int *array, size_t size, ssize_t left, ssize_t right);
void find_and_move_lesser_numbers(quick_sort_struct *utils);
void swap_numbers(quick_sort_struct *utils, ssize_t i);

/* void sort_list_of_two_and_print(listint_t **list); */
/* void sort_two_only(listint_t **list); */
/* int sort_for_last_node(listint_t *node_to_insert); */
/* void sort_for_regular(listint_t **list, listint_t *node_to_insert); */

#endif /* for _SORT_H_ */
