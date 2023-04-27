#include "header.h"

/**
 * ourHIS - prints out the history list, one command by  all line, preceded
 *              with line num, starting at 0 ..
 * @info: Structure containing potential arguments..
 *
 *  Return: 0
 */
int ourHIS(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unSetAliases - sets aliases to string..
 * @info: parameter struct..
 * @str: the string alias..
 *
 * Return: 0 on success, 1 on errors
 */
int unSetAliases(info_t *info, char *str)
{
	char *r, t;
	int ret;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	t = *r;
	*r = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*r = t;
	return (ret);
}

/**
 * SetAliases - sets aliases to string....
 * @info: parameter struct....
 * @str: the string alias....
 *
 * Return: 0 on success, 1 on errors.
 */
int SetAliases(info_t *info, char *str)
{
	char *r;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	if (!*++r)
		return (unSetAliases(info, str));

	unSetAliases(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * printingAliases - prints an alias string
 * @node: the aliases node
 *
 * Return: 0 on success, 1 on errors
 */
int printingAliases(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * myAalins - alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *
 *  Return: 0
 */
int myAalins(info_t *info)
{
	int i = 0;
	char *r = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (t = 1; info->argv[t]; t++)
	{
		r = _strchr(info->argv[t], '=');
		if (r)
			SetAliases(info, info->argv[t]);
		else
			printingAliases(node_starts_with(info->alias, info->argv[t], '='));
	}

	return (0);
}
