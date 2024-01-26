#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a new node at the given position
 * @h: A pointer to the head of the list
 * @idx: The index where the new node should be added
 * @n: The data to be put in the index idx
 *
 * Return: The address of the new node,
 *	   or NULL if :
 *	   1-it failed
 *	   2-it is not possible to add the new node at index idx
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp = *h;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; tmp && idx != 1; idx--)
		tmp = tmp->next;

	if (tmp == NULL)
		return (NULL);

	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = add_dnodeint(&(tmp->next), n);
	tmp->next = new;
	new->prev = tmp;

	return (new);
}
