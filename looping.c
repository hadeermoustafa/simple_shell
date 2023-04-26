#include "header.h"

/**
 * shell_loop - shell loop
 * @par: the parameter & return info struct
 * @vec: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int shell_loop(par_t *par, char **vec)
{
	ssize_t s = 0;
	int ret = 0;

	while (s != -1 && ret != -2)
	{
		clear_par(par);
		if (interactive(par))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(par);
		if (r != -1)
		{
			set_par(par, vec);
			ret = find_bltincmd(par);
			if (ret == -1)
				locate_cmd(par);
		}
		else if (interactive(par))
			_putchar('\n');
		free_par(par, 0);
	}
	write_history(par);
	free_par(par, 1);
	if (!interactive(par) && par->status)
		exit(par->status);
	if (ret == -2)
	{
		if (par->err_num == -1)
			exit(par->status);
		exit(par->err_num);
	}
	return (ret);
}

/**
 * find_bltincmd - finds a builtin command
 * @par: the parameter & return par struct
 *
 * Return: -1 if not found,
 *			0 if executed successfully,
 *			1 if found but not successful,
 *			-2 if signals exit()
 */
int find_bltincmd(par_t *par)
{
	int i, bltin_ret = -1;
	bltin_table bltintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; bltintbl[i].type; i++)
		if (_strcmp(par->argv[0], bltintbl[i].type) == 0)
		{
			par->line_count++;
			bltin_ret = bltintbl[i].func(par);
			break;
		}
	return (bltin_ret);
}

/**
 * locate_cmd - locate the cmd
 * @par: the parameter & return par struct
 *
 * Return: void
 */
void locate_cmd(par_t *par)
{
	char *addr = NULL;
	int i, j;

	par->path = par->argv[0];
	if (par->linecount_flag == 1)
	{
		par->line_count++;
		par->linecount_flag = 0;
	}
	for (i = 0, j = 0; par->arg[i]; i++)
		if (!is_delim(par->arg[i], " \t\n"))
			k++;
	if (!j)
		return;

	addr = find_path(par, _getenv(par, "PATH="), par->argv[0]);
	if (addr)
	{
		par->path = addr;
		fork_cmd(par);
	}
	else
	{
		if ((interactive(par) || _getenv(par, "PATH=")
			|| par->argv[0][0] == '/') && is_cmd(par, par->argv[0]))
			fork_cmd(par);
		else if (*(par->arg) != '\n')
		{
			par->status = 127;
			print_error(par, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @par: the parameter & return par struct
 *
 * Return: void
 */
void fork_cmd(par_t *par)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(par->path, par->argv, get_environ(par)) == -1)
		{
			free_par(par, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(par->status));
		if (WIFEXITED(par->status))
		{
			par->status = WEXITSTATUS(par->status);
			if (par->status == 126)
				print_error(par, "Permission denied\n");
		}
	}
}
