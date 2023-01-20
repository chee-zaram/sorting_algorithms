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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insertion_sort(listint_t **list, listint_t *current, listint_t *cur_prev);
void selection_sort(int *array, size_t size);

/* void sort_list_of_two_and_print(listint_t **list); */
/* void sort_two_only(listint_t **list); */
/* int sort_for_last_node(listint_t *node_to_insert); */
/* void sort_for_regular(listint_t **list, listint_t *node_to_insert); */

#endif /* for _SORT_H_ */
