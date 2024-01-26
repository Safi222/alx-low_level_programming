#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @n: The number to put inside the new node
 *
 * Return: A pointer to the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *tail = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (tail->next)
		tail = tail->next;

	tail->next = new;
	new->prev = tail;


	return (new);
}
