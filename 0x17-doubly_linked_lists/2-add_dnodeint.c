#include "lists.h"

/**
 * add_dnodeint - Add a new node at the biginning of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @n: The number to put inside the new node
 *
 * Return: A pointer to the head of the linked list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}
