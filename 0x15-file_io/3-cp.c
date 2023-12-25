#include "main.h"


/**
 * close_file - Close the file
 * @fd: The file descriptor of the file we want to close
 *
 * Return: void
 */
void close_file(int fd)
{
	int clr;

	clr = close(fd);

	if (clr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * main - Copy the content of a file to another file
 * @argc: The number of arguments passed to the function
 * @argv: An array of pointers to the arguments passed
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int src, dest, r = -1, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	src = open(argv[1], O_RDONLY);
	dest = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);

	while (r)
	{
		r = read(src, buffer, 1024);

		if (src == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		w = write(dest, buffer, r);

		if (dest == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	close_file(src);
	close_file(dest);

	return (0);
}
