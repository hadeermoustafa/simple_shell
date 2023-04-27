#include "header.h"

/**
 * **s_to_word - splits the string
 * @s: the string
 * @del: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **s_to_word(char *s, char *del)
{
	int i, j, k, m, numwords = 0;
	char **c;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!is_delim(s[i], del) && (is_delim(s[i + 1], del) || !s[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!c)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(s[i], del))
			i++;
		k = 0;
		while (!is_delim(s[i + k], del) && s[i + k])
			k++;
		c[j] = malloc((k + 1) * sizeof(char));
		if (!c[j])
		{
			for (k = 0; k < j; k++)
				free(c[k]);
			free(c);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			c[j][m] = s[i++];
		c[j][m] = 0;
	}
	c[j] = NULL;
	return (c);
}
/**
 * **s_to_word22 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **s_to_word22(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
