#include <stdio.h>
/**
 * main -Prints aphapet in lowercase
 *
 * Return:Always 0
 */
int main(void)
{
	char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 'e', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
	int i;

	for (i = 0; i < 6; i++)
	{
		putchar (alph[i]);
	}
		return (0);
}
