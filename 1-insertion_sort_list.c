#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * @list: double pointer to the doubly linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			tmp = current;
			if (current->next != NULL)
				current->next->prev = tmp->prev;

			current->prev->next = tmp->next;
			current = current->prev;
			tmp->prev = current->prev;
			tmp->next = current;
			if (current->prev != NULL)
				current->prev->next = tmp;

			current->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}
