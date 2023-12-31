#include "main.h"
/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */
void print_number(int n)
{
	unsigned int i, ten = 1, count = 0, x;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	if (n == 0)
		_putchar('0');
	x = n;
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	for (i = 1; i < count; i++)
	ten *= 10;
	while (count)
	{
		_putchar((n / ten) % 10 + '0');
		count--;
		ten /= 10;
	}
}
