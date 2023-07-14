#include <stdio.h>
/**
 * main -Prints aphapet in lowercase
 *
 * Return:Always 0
 */
int main(void)
{
	char alph[26] = "abcdefghijklmnopqrestuvwxyz";
	int i;

	for (i = 0; i < 6; i++)
	{
		putchar (alph[i]);
	}
		return (0);
}
