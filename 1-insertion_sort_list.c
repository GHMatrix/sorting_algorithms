#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	sorted = (*list)->next;

	while (sorted != NULL)
	{
	current = sorted;
	sorted = sorted->next;

	while (current->prev != NULL && current->n < current->prev->n)
	{
		tmp = current->prev;
		if (tmp->prev != NULL)
		tmp->prev->next = current;
		else
		*list = current;
		if (current->next != NULL)
		current->next->prev = tmp;
		current->prev = tmp->prev;
		tmp->next = current->next;
		current->next = tmp;
		tmp->prev = current;
		print_list((const listint_t *)*list);
	}
	}
}
