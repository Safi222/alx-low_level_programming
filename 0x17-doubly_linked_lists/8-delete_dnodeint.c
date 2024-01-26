#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete the node at the given position
 * @head: A pointer to the head of the list
 * @index: The index where the new node should be deleted
 *
 * Return: If it succeded - 1
 *	   If it failed - -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	for (; tmp && index; index--)
		tmp = tmp->next;

	if (tmp == NULL)
		return (-1);

	if (tmp == *head)
	{
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}


	free(tmp);

	return (1);
}
