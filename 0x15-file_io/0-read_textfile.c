#include "main.h"

/**
 * read_textfile - Read a text file and print it to the POSIX standard output
 * @filename: The name of the file to be printed
 * @letters: The number of letters to read and print from the file
 *
 * Return: The actual number of letters it could read and print
 *	   0 - if the file can not be opened, read, or if
 *	   filename is NULL, or if write fails or does not
 *	   write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (!filename)
		return (0);

	buffer = malloc(letters * sizeof(char));

	if (!buffer)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
