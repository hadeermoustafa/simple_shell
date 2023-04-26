#include "header.h"

/**
 * stringcpy - copy a string
 * @dest: the destination string to be copied to
 * @srcs: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *stringcpy(char *dest, char *srcs, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (srcs[i] != '\0' && i < n - 1)
	{
		dest[i] = srcs[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * conc2String - concatenates two strings
 *@dest: the first string
 *@srcs: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *conc2String(char *dest, char *srcs, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = srcs[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * locChar - locates a character in a string
 *@x: the string to be parsed
 *@r: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *locChar(char *x, char r)
{
	do {
		if (*x == r)
			return (x);
	} while (*x++ != '\0');

	return (NULL);
}
