#include "header.h"

/**
 * str_length - the length of a string
 * @str: the string whose length to check
 *
 * Return: length of string
 */
int str_length(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * compare_str - comparison of two strangs.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: - if str1 < str2, + if str1 > str2, 0 if str1 == str2
 */
int compare_str(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * begins_with - checks if it starts with haystack
 * @str: string
 * @substr: the substring
 *
 * Return: address of next char of haystack or NULL
 */
char *begins_with(const char *str, const char *substr)
{
	while (*substr)
		if (*substr++ != *str++)
			return (NULL);
	return ((char *)str);
}

/**
 * str_conc - concatenates two strings
 * @place: the place of the buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *str_conc(char *place, char *src)
{
	char *ret = place;

	while (*place)
		place++;
	while (*src)
		*place++ = *src++;
	*place = *src;
	return (ret);
}
