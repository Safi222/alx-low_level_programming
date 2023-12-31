#include "main.h"
/**
 * _strncat - conctinate a part only
 * @dest: a pointer to destination array
 * @src: a pointer to source array
 * @n: an input integer indicating how much to append
 * Description: concatinate n characters of source into dest
 *
 * Return: pointer to source
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, count = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[i] != '\0' && n)
	{
		*(dest + count) = src[i];
		i++;
		count++;
		n--;
	}
	*(dest + count) = '\0';
	return (dest);
}
