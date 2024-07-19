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
 * recursive_binary - The advanced binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @l: The Lower bound of the binary search
 * @r: The Upper bound of the binary search
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int recursive_binary(int *array, size_t l, size_t r, int value)
{
	size_t mid;

	print_array(array + l, r - l);
	if (l == r && array[l] != value)
		return (-1);

	mid = (r + l) / 2;

	if (array[mid] < value)
		l = mid + 1;
	else if (array[mid] > value)
		r = mid;
	else
	{
		if (mid == 0 || array[mid - 1] != array[mid])
			return (mid);
		r = mid;
	}
	return (recursive_binary(array, l, r, value));
}

/**
 * advanced_binary - The advanced binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
