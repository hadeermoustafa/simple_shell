#include "header.h"

/**
 * inter_M - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter_M(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * itsDelim - checks if character is a Delimeter
 * @x: the char to check
 * @Delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int itsDelim(char x, char *Delim)
{
	while (*Delim)
		if (*Delim++ == x)
			return (1);
	return (0);
}

/**
 *conAlpha - checks for alphabetic character
 *@x: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int conAlpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * conv_in_str - converts a string to an integer
 *@w: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int conv_in_str(char *w)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  w[i] != '\0' && flag != 2; i++)
	{
		if (w[i] == '-')
			sign *= -1;

		if (w[i] >= '0' && w[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (w[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
