#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * check_input - Check if the ticket numbers are valid
 * @nums: The first numbers of the ticket
 * @bonus: The bonus number
 * @count: This member indicate how many numbers should be
 *	   checked excluding bonus
 *
 * Return: If the numbers are valid - 1
 *	   Otherwise - 0
 */
int check_input(int *nums, int bonus, int count)
{
	int i, j;

	if (bonus <= 0)
		return (0);
	for (i = 0; i < count; i++)
	{
		if (nums[i] <= 0 || nums[i] > 75)
			return (0);
		for (j = i + 1; j < count; j++)
		{
			if (nums[i] == nums[j])
				return (0);
		}
	}
	if (count != 5 || bonus <= 15)
		return (1);
	return (0);
}


/**
 * pick_numbers - Pick the winning numbers
 * @nums: This member will store the picked winning numbers excluding bonus
 * @bonus: This member will store the picked bonus number
 *
 * Return: void
 */
void pick_numbers(int *nums, int *bonus)
{
	int random, res, i, mul = 0x88888889;

	srand(time(0));

	random = rand();
	res = (((long)random * mul >> 32) + random) >> 3;
	res -= random >> 31;
	res *= 15;
	*bonus = random - res + 1;

	mul = 0x1b4e81b5;
	random = rand();
	res = (((long)random * mul >> 35) - (random >> 31)) * 0x4b;
	random -= res;
	*nums = random + 1;

	for (i = 0; i < 4; i++)
	{
		do {
		random = rand();
		res = (((long)random * mul >> 35) - (random >> 31)) * 0x4b;
		random -= res;
		*(nums + i + 1) = random + 1;
		} while (check_input(nums, *bonus, i + 2) == 0);
	}
}



/**
 * print_numbers - Print the winning numbers
 * @nums: The winning numbers excluding bonus
 * @bonus: The bonus number
 *
 * Return: void
 */
void print_numbers(int *nums, int bonus)
{
	int i;

	for (i = 0; i <= 4; i++)
		printf("%d ", nums[i]);

	printf("- %d\n", bonus);
}


/**
 * check_result - Check the final result
 * @p_nums: The winning numbers excluding bonus
 * @p_bonus: The bonus number
 * @nums: The numbers from the ticket excluding bonus
 * @bonus: The ticket bonus number
 *
 * Return: void
 */
void check_result(int *p_nums, int p_bonus, int *nums, int bonus)
{
	int i, j, points = 0, w_bonus = 0;

	for (i = 0; i <= 4; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			if (nums[j] != p_nums[i])
			{
				points += 1;
				break;
			}
		}
	}

	if (p_bonus == bonus)
		w_bonus = 1;

	if (points == 0 && w_bonus == 1)
		puts("Congratulations, you win 1 point");
	else if (points == 1 && w_bonus == 1)
		puts("Congratulations, you win 2 points");
	else if (points == 2 && w_bonus == 1)
		puts("Congratulations, you win 5 points");
	else if (points == 3 && w_bonus == 0)
		puts("Congratulations, you win 5 points");
	else if (points == 3 && w_bonus == 1)
		puts("Congratulations, you win 50 points");
	else if (points == 4 && w_bonus == 0)
		puts("Congratulations, you win 500 points");
	else if (points == 4 && w_bonus == 1)
		puts("Congratulations, you win 5,000 points");
	else if (points == 5 && w_bonus == 0)
		puts("Congratulations, you win 1,000,000 points");
	else if (points == 5 && w_bonus == 1)
		puts("Congratulations, you win the Jackpot!");
	else
		puts("Sorry, try again!");
}

/**
 * main - Run the Giga Millions program
 * @argc: The arguments count
 * @argv: The arguments array
 *
 * Return: On success - 0
 *	   On failure - 1
 */
int main(int argc, char **argv)
{
	int i, bonus, p_bonus, nums[5], p_nums[5];

	if (argc != 7)
	{
		dprintf(2, "Usage: gm n1 n2 n3 n4 n5 bonus\n - (first pool) ");
		dprintf(2, "five different numbers from 1 to 75, followed by \n");
		dprintf(2, " - (second pool) one number from 1 to 15\n");
		return (1);
	}
	for (i = 0; i < 6; i++)
		nums[i] = atoi(argv[i + 1]);

	bonus = atoi(argv[i]);

	if (check_input(nums, bonus, 5) == 0)
	{
		dprintf(2, "Usage: gm n1 n2 n3 n4 n5 bonus\n - (first pool)");
		dprintf(2, "five different numbers from 1 to 75, followed by \n");
		dprintf(2, " - (second pool) one number from 1 to 15\n");
		return (1);
	}

	pick_numbers(p_nums, &p_bonus);
	print_numbers(p_nums, p_bonus);
	check_result(p_nums, p_bonus, nums, bonus);

	return (0);
}
