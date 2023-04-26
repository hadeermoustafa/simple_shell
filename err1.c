#include "header.h"

/**
 * conINTtoSTR - converts a string to integer
 * @st: the string to be converted
 * Return: 0 if no numbers in string, otherwise -1 on error
 *
 */
int conINTtoSTR(char *st)
{
	int z = 0;
	unsigned long int result = 0;

	if (*st == '+')
		st++;
	for (z = 0;  st[z] != '\0'; z++)
	{
		if (st[z] >= '0' && st[z] <= '9')
		{
			result *= 10;
			result += (st[z] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * printError - print error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 *
 * Return: 0 if no numbers in string, otherwise -1
 *
 */
void printError(info_t *info, char *estr)
{
	printINstr(info->fname);
	printINstr(": ");
	printD(info->line_count, STDERR_FILENO);
	printINstr(": ");
	printINstr(info->argv[0]);
	printINstr(": ");
	printINstr(estr);
}

/**
 * printD - function prints a decmal value
 * @input: the input
 * @fild: the filedescriptor to write to
 *
 * Return: number of characters printed..
 */
int printD(int input, int fild)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fild == STDERR_FILENO)
		__putchar = ePutCharacter;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convNum - converter function, a clone of itoa
 * @num: number..
 * @base: base.
 * @flags: arg flags
 *
 * Return: str
 */
char *convNum(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rmcomments - function rep. first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: 0
 */
void rmcomments(char *buf)
{
	int q;

	for (q = 0; buf[q] != '\0'; q++)
		if (buf[q] == '#' && (!q || buf[q - 1] == ' '))
		{
			buf[q] = '\0';
			break;
		}
}
