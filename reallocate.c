#include "header.h"

/**
 **set_memory - fills memory
 *@ptr: the pointer
 *@bytes: the byte to fill the pointer
 *@amt: the amount of bytes
 *Return: (s) a pointer to the memory area s
 */
char *set_memory(char *ptr, char bytes, unsigned int amt)
{
	unsigned int i;

	for (i = 0; i < amt; i++)
		ptr[i] = bytes;
	return (ptr);
}

/**
 * freestr - frees a string of strings
 * @strofstr: a string of strings
 */
void freestr(char **strofstr)
{
	char **p = strofstr;

	if (!strofstr)
		return;
	while (*strofstr)
		free(*strofstr++);
	free(p);
}

/**
 * reallocate - reallocates a block of memory
 * @ptr: pointer
 * @prev: byte size of previous block
 * @post: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *reallocate(void *ptr, unsigned int prev, unsigned int post)
{
	char *b;

	if (!ptr)
		return (malloc(post));
	if (!post)
		return (free(ptr), NULL);
	if (post == prev)
		return (ptr);

	b = malloc(post);
	if (!b)
		return (NULL);

	prev = prev < post ? prev : post;
	while (prev--)
		b[prev] = ((char *)ptr)[prev];
	free(ptr);
	return (b);
}

