#include "search_algos.h"

/**
 * linear_skip - The jump search algorithm in a skip list
 * @list: A pointer to the head of the list to search in
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *l, *r = list;

	if (list == NULL)
		return (NULL);
	do {
		l = r;
		r = r->express;
		printf("Value checked at index [%ld] = [%d]\n", r->index, r->n);
	} while (r->express && (r->n < value));

	if (r->express == NULL && r->n < value)
	{
		l = r;
		while (r->next)
			r = r->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", l->index, r->index);

	for (; l && l->index <= r->index; l = l->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", l->index, l->n);
		if (l->n == value)
			return (l);
	}
	return (NULL);
}
