#include "search_algos.h"
#include <math.h>

/**
 * increment - Increment the pointer by specific step
 * @list: A pointer to the head of the list
 * @step: The increment step
 *
 * Return: The new node after the increment
 */
listint_t *increment(listint_t *list, size_t step)
{
	size_t i;

	for (i = 0; i < step && list->next; i++)
		list = list->next;
	return (list);
}

/**
 * jump_list - The jump search algorithm in a singly linked list
 * @list: A pointer to the head of the list to search in
 * @size: The number of nodes in list
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *l, *r = list;

	if (list == NULL)
		return (NULL);
	do {
		l = r;
		r = increment(r, step);
		printf("Value checked at index [%ld] = [%d]\n", r->index, r->n);
	} while (r->next && r->index < size && (r->n < value));

	if (r->next)
		printf("Value found between indexes [%ld] and [%ld]\n", l->index, r->index);
	else
		printf("Value found between indexes [%ld] and [%ld]\n", l->index, size - 1);

	for (; l && l->index <= r->index; l = l->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", l->index, l->n);
		if (l->n == value)
			return (l);
	}
	return (NULL);
}
