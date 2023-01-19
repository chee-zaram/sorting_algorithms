#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort - Sorts a doubly linked list of integers in ascending order
 * @list: Address of the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_to_insert = NULL, *next_to_insert = NULL;
	listint_t  *new_last, *new_prev, *new_next, *old_next;

	if (!list || !*list)
		return;

	if (!(*list)->next)
		return;

	if (!(*list)->next->next)
	{
		if ((*list)->next->n < (*list)->n)
		{
			(*list)->next->prev = NULL;
			(*list)->next->next = *list;
			(*list)->prev = (*list)->next;
			*list = (*list)->next;
			(*list)->next->next = NULL;
			print_list(*list);
		}
		return;
	}

	if ((*list)->next->n < (*list)->n)
	{
		(*list)->next->prev = NULL;
		(*list)->next->next = *list;
		(*list)->prev = (*list)->next;
		*list = (*list)->next;
		print_list(*list);
	}

	node_to_insert = (*list)->next->next;
	next_to_insert = node_to_insert->next;

	while (node_to_insert)
	{
		if (!node_to_insert->next && node_to_insert->prev && node_to_insert->prev->prev)
		{
			if (node_to_insert->prev->n <= node_to_insert->n)
				break;

			new_prev = node_to_insert->prev->prev;
			new_last = node_to_insert->prev;

			new_last->next = NULL;
			new_last->prev = node_to_insert;
			new_prev->next = node_to_insert;
			node_to_insert->prev = new_prev;
			node_to_insert->next = new_last;
			print_list(*list);

			if (node_to_insert->prev && node_to_insert->prev->n <= node_to_insert->n)
				break;
		}

		else if (node_to_insert->prev && node_to_insert->prev->n > node_to_insert->n)
		{
			new_prev = node_to_insert->prev->prev;
			new_next = node_to_insert->prev;
			old_next = node_to_insert->next;

			old_next->prev = new_next;
			new_next->next = old_next;
			new_next->prev = node_to_insert;
			node_to_insert->next = new_next;
			if (new_prev)
			{
				new_prev->next = node_to_insert;
				node_to_insert->prev = new_prev;
			}
			else
			{
				node_to_insert->prev = NULL;
				*list = node_to_insert;
			}
			print_list(*list);
		}
		else
		{
			node_to_insert = next_to_insert;
			if (next_to_insert && next_to_insert->next)
				next_to_insert = next_to_insert->next;
		}
	}
}
