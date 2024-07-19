#include "search_algos.h"
#include <math.h>

/**
 * jump_search - The jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size), l = 0, r = 0;

	if (array == NULL)
		return (-1);
	do {
		printf("Value checked array[%ld] = [%d]\n", r, array[r]);
		if (array[l] == value)
			return (l);
		l = r;
		r += step;
	} while (r < size && array[r] < value);

	printf("Value found between indexes [%ld] and [%ld]\n", l, r);

	while (l <= r)
	{
		printf("Value checked array[%ld] = [%d]\n", l, array[l]);
		if (array[l] == value)
			return (l);
		if (array[l] > value || ++l == size)
			break;
	}
	return (-1);
}
