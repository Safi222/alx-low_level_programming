#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generate a key depending on a username for crackme5
 * @argc: Arguments Count
 * @argv: Arguments Vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	unsigned int i, b;
	size_t len, ret;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char *name, p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	name = argv[1];
	len = strlen(name);
	p[0] = l[(len ^ 59) & 63];
	for (i = 0, ret = 0; i < len; i++)
		ret += name[i];
	p[1] = l[(ret ^ 79) & 63];
	for (i = 0, b = 1; i < len; i++)
		b *= name[i];
	p[2] = l[(b ^ 85) & 63];
	for (b = name[0], i = 0; i < len; i++)
		if ((char)b < name[i])
			b = name[i];
	srand(b ^ 14);
	p[3] = l[rand() & 63];
	for (b = 0, i = 0; i < len; i++)
		b += name[i] * name[i];
	p[4] = l[(b ^ 239) & 63];
	for (b = 0, i = 0; (char)i < name[0]; i++)
		b = rand();
	p[5] = l[(b ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
