#include "header.h"

/**
 * is_exe - determines if a file is an executable command
 * @data: the data struct
 * @addr: address to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_exe(data_t *data, char *addr)
{
	struct stat st;

	(void)data;
	if (!addr || stat(addr, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * double_chars - duplicates the chars
 * @addstr: the PATH string
 * @begin: begins index
 * @end: ends index
 *
 * Return: pointer to new buffer
 */
char *double_chars(char *addstr, int begin, int end)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = begin; i < end; i++)
		if (addstr[i] != ':')
			buf[k++] = addstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * cmd_path - finds this cmd
 * @data: the info struct
 * @addrstr: the string
 * @cmd: the cmd to search for
 *
 * Return: full path of cmd if found or NULL
 */
char *cmd_path(data_t *data, char *addrstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *addr;

	if (!addrstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_exe(data, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!addrstr[i] || addrstr[i] == ':')
		{
			addr = double_chars(addrstr, curr_pos, i);
			if (!*addr)
				_strcat(addr, cmd);
			else
			{
				_strcat(addr, "/");
				_strcat(addr, cmd);
			}
			if (is_exe(data, addr))
				return (addr);
			if (!addrstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
