#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Head of the doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *current, *key;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;
	key = current->next;
	temp1 = key;
	temp2 = current->prev;
	while (current != NULL)
	{
		while (current->n <= temp2->n && temp2 != NULL)
		{
			temp2->next = temp1;
			if (temp1 != NULL)
				temp1->prev = temp2;
			current->prev = temp2->prev;
			temp2->prev = current;
			current->next = temp2;
			temp2 = current->prev;
			if (temp2 != NULL)
				temp2->next = current;
			else
			{
				*list = current;
				print_list(*list);
				break;
			}
			temp1 = current->next;
			print_list(*list);
		}
		if (key != NULL)
		{
			current = key;
			key = current->next;
			temp1 = current->next;
			temp2 = current->prev;
		}
		else
			break;
	}
}
