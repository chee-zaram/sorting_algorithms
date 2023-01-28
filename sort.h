#ifndef _SORT_H_
#define _SORT_H_

#define FALSE 0
#define TRUE  1

#define VALID_RIGHT_CHILD_GREATER_THAN_PARENT \
	(parent >= 0 && right_child < work_size && array[parent] < array[right_child])

#define VALID_LEFT_CHILD_GREATER_THAN_PARENT \
	(parent >= 0 && array[parent] < array[left_child])

#define VALID_PREV_PARENT_AND_SWAPPED \
	(prev_parent >= 0 && prev_parent != parent)

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
	const int	  n;
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
	int    *array;
	int	pivot;
	ssize_t curr_int_idx;
	ssize_t left;
	ssize_t right;
	ssize_t pivot_idx;
	size_t	size;
} quick_sort_struct;

/**
 * struct shell_sort - Utility structure for values used during shell sort
 * @array: Array of ints
 * @curr_idx: The current index being analyzed
 * @high_idx: The higher index being analyzed
 * @i: A utility counter
 * @idx: A utility index used during checking is the array is sorted
 * @insert: Index at while number to be inserted is during insertion sort
 * @interval: Interval between higher index and lower index in shell sort
 * @size: Size of the array
 */
typedef struct shell_sort
{
	int   *array;
	size_t curr_idx;
	size_t high_idx;
	size_t i;
	size_t idx;
	size_t insert;
	size_t interval;
	size_t size;
} shell_sort_struct;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
void insertion_sort(listint_t **list, listint_t *current, listint_t *cur_prev);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_sort_lomuto(int *array, size_t size, ssize_t left, ssize_t right);
void find_and_move_lesser_numbers(quick_sort_struct *utils);
void swap_numbers(quick_sort_struct *utils);

void shell_sort(int *array, size_t size);
void compare_and_swap(shell_sort_struct *utils);
int  is_sorted(shell_sort_struct *utils);
void do_insertion_sort(shell_sort_struct *utils);
void check_and_swap(shell_sort_struct *utils);

void	   cocktail_sort_list(listint_t **list);
listint_t *bubble_forward(listint_t **list, int *sorted);
void	   bubble_backward(listint_t **list, listint_t *tail_ref, int *sorted);
void	   swap_list_of_two(listint_t **list);

void counting_sort(int *array, size_t size);
int  find_max(int *array, size_t size);
void sort(int *array, int *count, int *sorted_array, size_t size);

void merge_sort(int *array, size_t size);
void copy_array(int *array, int *temp_array, size_t size);
void split(int *temp_array, size_t beg, size_t end, int *array);
void merge(int *array, size_t beg, size_t mid, size_t end, int *temp_array);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t or_size, size_t work_size, int parent);
void swap(int *array, size_t idx_1, size_t idx_2);
void extract_and_insert(int *array, size_t or_size, size_t max_idx);

void  radix_sort(int *array, size_t size);
int **create_queue(void);
int   allocate_to_each_queue(int **queues, size_t size);
void  lsd_sort(int **queues, int *array, size_t size, int divisor);

#endif /* for _SORT_H_ */
