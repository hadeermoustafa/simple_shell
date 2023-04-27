#include "header.h"

/**
 * enveLinve - prints the current env
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: 0
 */
int enveLinve(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * getMyenv - gets the value of an environ variable.
 * @info: Structure containing potential arguments.
 * @name: environment var namees.
 *
 * Return: the value
 */
char *getMyenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *r;

	while (node)
	{
		r = starts_with(node->str, name);
		if (r && *r)
			return (r);
		node = node->next;
	}
	return (NULL);
}

/**
 * aNewEnvv - Initialize a new environment variable,
 *
 * @info: Structure containing potential arguments. Used to maintain
 *
 *  Return: 0
 */
int aNewEnvv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Worng number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * rmVarEnvv - Remove an env var
 * @info: Structure containing potential arguments. Used to maintain..
 *
 *  Return: 0
 */
int rmVarEnvv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * popEnvLl - populates env linked lists..
 * @info: Structure containing potential arguments. Used to maintain..
 *
 * Return: 0
 */
int popEnvLl(info_t *info)
{
	list_t *node = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
