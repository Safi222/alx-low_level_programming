/**
 * calc_len - calculates the length of a string
 * @str: The string to calculate its length
 *
 * Return: The length of the string
 */
int calc_len(char *str)
{
	int len = 0;

	while (*str++)
	{
		len++;
	}
	return (len);
}

/**
 * add_strings - Adds the numbers stored in two strings.
 * @n1: The string containing the first number to be added.
 * @n2: The string containing the second number to be added.
 * @r: The buffer to store the result.
 * @r_index: The current index of the buffer.
 *
 * Return: If r can store the sum - a pointer to the result.
 *	   If r cannot store the sum - 0.
 */
char *add_strings(char *n1, char *n2, char *r, int r_index)
{
	int sum, carry = 0;

	for (; *n1 && *n2; n1--, n2--, r_index--)
	{
		sum = (*n1 - '0') + (*n2 - '0') + carry;
		*(r + r_index) = (sum % 10) + '0';
		carry = sum / 10;
	}

	for (; *n1; n1--, r_index--)
	{
		sum = (*n1 - '0') + carry;
		*(r + r_index) = (sum % 10) + '0';
		carry = sum / 10;
	}
	for (; *n2; n2--, r_index--)
	{
		sum = (*n2 - '0') + carry;
		*(r + r_index) = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry && r_index >= 0)
	{
		*(r + r_index) = (carry % 10) + '0';
		return (r + r_index);
	}
	else if (carry && r_index < 0)
	{
		return (0);
	}
	return (r + r_index + 1);
}
/**
 * infinite_add - Adds two numbers.
 * @n1: The first number to be added.
 * @n2: The second number to be added.
 * @r: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: If r can store the sum - a pointer to the result.
 *	   If r cannot store the sum - 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int n1_len = calc_len(n1);
	int n2_len = calc_len(n2);

	if (size_r <= n1_len + 1 || size_r <= n2_len + 1)
	{
		return (0);
	}

	n1 += n1_len - 1;
	n2 += n2_len - 1;
	*(r + size_r) = '\0';

	return (add_strings(n1, n2, r, --size_r));
}
