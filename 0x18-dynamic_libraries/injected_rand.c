#include <stdio.h>

/**
 * rand - New random function to win the jackpot
 *
 * Return: A random integer
 */
int rand(void)
{
	static int ct = -1;

	ct++;

	if (ct == 0 || ct == 1)
		return (8);
	else if (ct == 2)
		return (7);
	else if (ct == 3)
		return (9);
	else if (ct == 4)
		return (23);
	else if (ct == 5)
		return (74);
	return (ct * ct % 3456);
}
