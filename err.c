#include "header.h"

/**
 * printINstr - print input string
 * @str: the string printed
 *
 * Return: ...
 */
void printINstr(char *str)
{
	int z = 0;

	if (!str)
		return;
	while (str[z] != '\0')
	{
		ePutCharacter(str[z]);
		z++;
	}
}

/**
 * ePutCharacter - writes the character x to stderr
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int ePutCharacter(char x)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(2, buf, y);
		y = 0;
	}
	if (x != BUF_FLUSH)
		buf[y++] = x;
	return (y);
}

/**
 * ePutfiled  - writes the character x to given file_d
 * @x: The character to print
 * @file_d: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int ePutfiled(char x, int file_d)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
		y = 0;
	}
	if (x != BUF_FLUSH)
		buf[y++] = x;
	return (1);
}

/**
 * ePutsfiled - prints an input string
 * @str: the string to be printed
 * @file_d: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int ePutsfiled(char *str, int file_d)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += ePutfiled(*str++, file_d);
	}
	return (i);
}
