#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list
 *
 * @h: A pointer to the head of the doubly-linked list
 * @first: A pointer to the first node to swap
 * @second: The second node to swap
 */
void swap_nodes(listint_t **h, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev)
		(*first)->prev->next = second;
	else
		*h = second;
	(*first)->prev = second;
	*first = second->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in asc
 *
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *iter, *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	for (iter = (*list)->next; iter; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
