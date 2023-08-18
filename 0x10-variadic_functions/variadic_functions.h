#ifndef VARIADIC_FUNCTION_H
#define VARIADIC_FUNCTION_H


#include <stdarg.h>
/**
 * struct printer - A new struct type defining a printer
 *      on the symbol passed
 * @symbol: The character that defines the printer function
 * @print: A pointer to the chosen printer function
 */
typedef struct printer
{
 char *symbol;
 void (*print)(va_list);
} printer_t;

/**
 * sum_them_all - Sum all of the passed parameters
 * @n: The number of parameters that will be passed after n
 *
 * Return: The sum if n > 0, otherwise 0
 */
int sum_them_all(const unsigned int n, ...);

/**
 * print_numbers - Print all of passed numbers
 * @separator: The string to be printed between numbers
 * @n: The number of integers passed to the function
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...);

/**
 * print_strings - Print all of passed strings
 * @separator: The string to be printed between strings
 * @n: The number of strings passed to the function
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...);

/**
 * print_all - Print any argument passed
 * @format: A list of types of arguments passed to the function:
 *     c: char
 *     i: integer
 *     f: float
 *     s: char *
 *     any other char should be ignored
 *
 * Return: void
 */
void print_all(const char * const format, ...);

#endif
