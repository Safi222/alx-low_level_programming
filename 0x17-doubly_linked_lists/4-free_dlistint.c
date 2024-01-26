#include "lists.h"

/**
 * free_dlistint - Free a dlistint_t list
 * @head: A pointer to the linked list to be freed
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);

		head = tmp;
	}
}
