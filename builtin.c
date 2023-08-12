#include "shell.h"
/**
 * _shellexit - This will exit the shell
 * @inf: Structure containing arguments. Used
 * to maintian constant function ptototype.
 * Return: exits with a given exit status
 * (0) if inf.argv[0] != "exit"
 */
int _shellexit(info_t *inf)
{
	int checkexit;

	if (inf->argv[1]) /* if there's any exit */
	{
		checkexit = _erratoi(inf->argv[1]);
		if (checkexit == -1)
		{
			inf->status = 2;
			print_error(inf, "Ilegal input number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _changecd - This will change the current directory of the process
 * @inf: Structure containing arguments. Used to maintain
 * constant function prototype
 * Return: Always 0
 */
int _changecd(info_t *inf)
{
	char *s, *dir, buffer[1024];
	int chrdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure message here<<\n");
	if (!inf->argv[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			chrdir_ret = /* TODO: what should this be ? */
				chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			chrdir_ret = chdir(dir);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chrdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		chrdir_ret = chdir(inf->argv[1]);
	if (chrdir_ret == -1)
	{
		print_error(inf, "can not change directory to ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current dir of the process
 * @inf: Structure containing arguments. Used to maintain
 * constant function prototype
 * Return: Always 0
 */
int myhelp(info_t *inf)
{
	char **arg_arr;

	arg_arr = inf->argv;
	_puts("Help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr); 
	return (0);
}
