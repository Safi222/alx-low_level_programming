#include "main.h"
/**
 * reverse_array - reverse
 * @a: pointer to int a array
 * @n: poimter to int b size of array
 * Description: reverses the content of an array of integers
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int index = 0, tmp;

	for (index = 0; index < n / 2; index++)
	{
		tmp = a[index];
		a[index] = a[n - index - 1];
		a[n - index - 1] = tmp;
	}
}
