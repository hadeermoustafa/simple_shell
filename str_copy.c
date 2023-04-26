#include "header.h"

/**
 * cpy_str - copy a string
 * @place: the place
 * @s: the source
 *
 * Return: pointer to its place
 */
char *cpy_str(char *place, char *s)
{
	int i = 0;

	if (place == s || s == 0)
		return (place);
	while (s[i])
	{
		place[i] = src[i];
		i++;
	}
	place[i] = 0;
	return (place);
}

/**
 * doub_str - doubles a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *doub_str(const char *str)
{
	int size = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	for (size++; size--;)
		ret[size] = *--str;
	return (ret);
}

/**
 *prt_input - prints an input string
 *@s: the string to be printed
 *
 * Return: void
 */
void prt_input(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
