#include "header.h"

/**
 * give_space - give space to pointer
 * @ptr_add: address of the pointer to frees
 *
 * Return: 1 if freed, else return 0.
 */
int give_space(void **ptr_add)
{
	if (ptr_add && *ptr_add)
	{
		free(*ptr_add);
		*ptr_add = NULL;
		return (1);
	}
	return (0);
}
