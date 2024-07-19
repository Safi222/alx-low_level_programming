#include "search_algos.h"

/**
 * interpolation_search - The interpolation search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0, h = size - 1, pos;

	if (array == NULL)
		return (-1);
	while (l <= h)
	{
		pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		if (pos < size)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}
		if (array[pos] > value)
			h = pos - 1;
		if (array[pos] < value)
			l = pos + 1;
		else
			return (pos);
	}
	return (-1);
}
