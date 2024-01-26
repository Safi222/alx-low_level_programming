#include "lists.h"

/**
 * get_dnodeint_at_index - Get the nth node of a dlistint_t linked list
 * @head: A pointer to the head of the list
 * @index: The index of the node to retrieve
 *
 * Return: The nth node of a dlistint_t linked list,
 *	   or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head && index)
	{
		index--;
		head = head->next;
	}

	return (head);
}
