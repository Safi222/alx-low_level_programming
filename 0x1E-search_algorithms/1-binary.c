#include "search_algos.h"

/**
 * print_array - Print the elements of the array
 * @array: A pointer to the first element of the array to print
 * @size: The number of elements to print
 *
 * Return: Void
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * binary_search - The binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, mid;

	if (array == NULL)
		return (-1);
	while (l <= r)
	{
		mid = (l + r) / 2;

		print_array(array + l, r - l);
		if (array[mid] < value)
			l = mid + 1;
		else if (array[mid] > value)
			r = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
