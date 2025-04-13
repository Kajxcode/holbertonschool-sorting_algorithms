#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;
		temp = current;
		current = current->next;

		while (insert && temp->n < insert->n)
		{
			if (insert->prev)
				insert->prev->next = temp;
			else
				*list = temp;

			if (temp->next)
				temp->next->prev = insert;

			insert->next = temp->next;
			temp->prev = insert->prev;

			temp->next = insert;
			insert->prev = temp;

			insert = temp->prev;
			print_list(*list);
		}
	}
}
