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
 * bs - The binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @l: The lower bound for the binary search
 * @r: The upper bound for the binary search
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int bs(int *array, size_t l, size_t r, int value)
{
	size_t mid;

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

/**
 * exponential_search - The exponential search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	for (i = 1; i < size && array[i] < value; i *= 2)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	if (i < size)
		size = i;
	else
		size--;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, size);
	return (bs(array, i / 2, size, value));
}
