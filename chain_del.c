#include "header.h"

/**
 * chain_del - test if current char in buffer is a chain delimeter
 * @data: the parameter struct
 * @buff: the char buffer
 * @addr: address of current position in buff
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chain_del(data_t *data, char *buff, size_t *addr)
{
	size_t j = *addr;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		data->cmd_buff_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		data->cmd_buff_type = CMD_AND;
	}
	else if (buff[j] == ';') /* found end of this command */
	{
		buff[j] = 0; /* replace semicolon with null */
		data->cmd_buff_type = CMD_CHAIN;
	}
	else
		return (0);
	*addr = j;
	return (1);
}

/**
 * chCH - checks we should continue chaining based on last status
 * @data: the parameter struct
 * @buff: the char buffer
 * @addr: address of current position in buff
 * @i: starting position in buff
 * @len: length of buff
 *
 * Return: Void
 */
void chCH(data_t *data, char *buff, size_t *addr, size_t i, size_t len)
{
	size_t j = *addr;

	if (data->cmd_buff_type == CMD_AND)
	{
		if (data->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (data->cmd_buff_type == CMD_OR)
	{
		if (!data->status)
		{
			buff[i] = 0;
			j = len;
		}
	}

	*addr = j;
}

/**
 * replaceaLI - replaces an aliases in the tokenized string
 * @data: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replaceaLI(data_t *data)
{
	int i;
	list_t *node;
	char *addr;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(data->alias, data->argv[0], '=');
		if (!node)
			return (0);
		free(data->argv[0]);
		addr = _strchr(node->str, '=');
		if (!addr)
			return (0);
		addr = _strduaddr(addr + 1);
		if (!addr)
			return (0);
		data->argv[0] = addr;
	}
	return (1);
}

/**
 * reVars - replaces vars in the tokenized string
 * @data: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int reVars(data_t *data)
{
	int i = 0;
	list_t *node;

	for (i = 0; data->argv[i]; i++)
	{
		if (data->argv[i][0] != '$' || !data->argv[i][1])
			continue;

		if (!_strcmp(data->argv[i], "$?"))
		{
			replace_string(&(data->argv[i]),
				_strdup(convert_number(data->status, 10, 0)));
			continue;
		}
		if (!_strcmp(data->argv[i], "$$"))
		{
			replace_string(&(data->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(data->env, &data->argv[i][1], '=');
		if (node)
		{
			replace_string(&(data->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&data->argv[i], _strdup(""));

	}
	return (0);
}
/**
 * reString - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int reString(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
