#ifndef MAIN_H
#define MAIN_H

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c);

/**
 * _islower - Check for lowercase character.
 * @c: The character to check
 *
 * Return: 1 if c is lowercase 0 otherwise.
 */
int _islower(int c);

/**
 * _isalpha - Check for alphabetic character.
 * @c: The character to check
 *
 * Return: 1 if c is a letter 0 otherwise.
 */
int _isalpha(int c);

/**
 * _abs - Compute the absolute value of an integer.
 * @n: The number to compute its absolute value
 *
 * Return: The absolute value.
 */
int _abs(int n);

/**
 * _isupper - Check for uppercase character.
 * @c: The character to check
 *
 * Return: 1 if c is uppercase 0 otherwise.
 */
int _isupper(int c);

/**
 * _isdigit - Check for a digit.
 * @c: The character to check
 *
 * Return: 1 if c is digit 0 otherwise.
 */
int _isdigit(int c);

/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(char *s);

/**
 * _puts - Print a string, followed by a new line, to stdout
 * @s: The string to be printed
 *
 * Return: void
 */
void _puts(char *s);

/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, char *src);

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s);

/**
 * _strcat - Concatenate two strings
 * @src: The string to be appended
 * @dest: The string to append to it
 *
 * Return: The pointer to the destination.
 */
char *_strcat(char *dest, char *src);

/**
 * _strncat - Concatenate two strings
 * @src: The string to be appended
 * @dest: The string to append to it
 * @n: The number of the concatenated chracters
 *
 * Return: The pointer to the destination.
 */
char *_strncat(char *dest, char *src, int n);

/**
 * _strncpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 * @n: The number of the copied characters
 *
 * Return: The pointer to the destination.
 */
char *_strncpy(char *dest, char *src, int n);

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The string to compare with the first
 * Return: Zero if both strings are identical,
 *	   greater than zero when the matching
 *	   character of left string has greater
 *	   ASCII value than the character of
 *	   he right string, less than zero
 *	   when the left character has a smaller
 *	   value.
 */
int _strcmp(char *s1, char *s2);

/**
 * memset - Fill memory with a constant byte
 * @s: A pointer to the memory area to be filled
 * @b: The constant byte to fill with
 * @n: The number of bytes to be filled
 *
 * Return: A pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n);

/**
 * _memcpy - Copy n bytes into the desired destination
 * @dest: A pointer to the memory area to be filled
 * @src: The memory area to take bytes from
 * @n: The number of bytes to be filled
 *
 * Return: A pointer to the destintaion
 */
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * _strchr - Locate a character in a string
 * @s: The string to be searched
 * @c: The character to find
 *
 * Return: A pointer to the occurrence of the character c
 *	   in the string s, or NULL if the character is
 *	   not found
 */
char *_strchr(char *s, char c);

/**
 * _strspn - Git the length of a prefix substring
 * @s: The string to be searched
 * @accept: The substring that should be in s
 *
 * Return: The number of bytes in the initial
 *	   segment of s which consist
 *	   only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept);

/**
 * _strpbrk - Search for any of a set of bytes
 * @s: The string to be searched
 * @accept: The substring that should contain a byte in s
 *
 * Return: A pointer to the byte in s that matches
 *	   one of the bytes in accept,or NULL if
 *	   no such byte is found
 */
char *_strpbrk(char *s, char *accept);

/**
 * _strstr - Locate a substring
 * @haystack: The string to be searched
 * @needle: The substring that should be located
 *
 * Return: A pointer to the beginning of the located
 *	   substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle);

#endif
