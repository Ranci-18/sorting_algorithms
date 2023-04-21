#include <stdio.h>
#include "sort.h"
/**
 *insertion_sort_list - sorts linked list using insertion sort algorithm
 *@list: head of linked list
 *
 *Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *prev_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = node->next)
	{
		prev_node = node->prev;
		while (prev_node != NULL && prev_node->n > node->n)
		{
			temp = prev_node;
			prev_node = prev_node->prev;

			temp->next = node->next;
			if (temp->next != NULL)
				temp->next->prev = temp;
			node->prev = temp->prev;
			node->next = temp;
			if (node->prev != NULL)
				node->prev->next = node;
			temp->prev = node;
			if (temp == *list)
				*list = node;
			print_list(*list);
		}
	}
}
