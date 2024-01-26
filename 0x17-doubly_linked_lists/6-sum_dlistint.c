#include "lists.h"

/**
 * sum_dlistint - Calculate the sum of all the data (n) of dlistint_t list
 * @head: A pointer to the first node in the linked list
 *
 * Return: The sum of data or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
