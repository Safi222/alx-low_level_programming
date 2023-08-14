#include <main.h>
/**
 * _strcat - Concatenate two strings
 * @src: The string to be appended
 * @dest: The string to append to it
 *
 * Return: The pointer to the destination.
 */
char *_strcat(char *dest, char *src)
{
	int count = 0, i = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[i] != '\0')
	{
		*(des + count) = src[i];
		i++;
		count++;
	}
	*(des + count) = '\0';
	return (dest);
}
