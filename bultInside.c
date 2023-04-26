#include "header.h"

/**
 * getOutt - exits out the shell
 * @info: Structure  that containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int getOutt(info_t *info)
{
	int exitchecking;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitchecking = _erratoi(info->argv[1]);
		if (exitchecking == -1)
		{
			info->status = 2;
			print_error(info, "Wrong Number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * chTHacurrnetDIR - changes the current directory out of the process.
 * @info: Structure containing potential arguments. Used to maintain.
 *
 *  Return: Always 0
 */
int chTHacurrnetDIR(info_t *info)
{
	char *x, *dir, buffer[1024];
	int chdir_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * chaningPID - changes the dir of the process.
 * @info: Structure containing potential arguments.
 *
 *  Return: 0
 */
int chaningPID(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works!!. Function not yet implemented... \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
