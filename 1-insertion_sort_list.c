#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list.
 * @list: list to be sorted.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		previous = current;
		current = current->next;
		while (previous->prev && previous)
		{
			if (previous->prev->n > previous->n)
			{
				swap(previous->prev, previous);
				if (!previous->prev)
					*list = previous;
				print_list(*list);
			}
			else
				previous = previous->prev;
		}
	}
}

/**
 * swap - a function that swaps nodes.
 * @current: current node.
 * @previous: previous node.
*/
void swap(listint_t *current, listint_t *previous)
{
	if (current->prev)
		current->prev->next = previous;
	if (previous->next)
		previous->next->prev = current;
	current->next = previous->next;
	previous->prev = current->prev;
	current->prev = previous;
	previous->next = current;
}
