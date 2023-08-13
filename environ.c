#include "shell.h"
/**
 * _printenv - this will prints the current environment
 * @inf: Structure containing possible arguments. Used to keep
 * constant function prototype
 * Return: Always 0
 */
int _printenv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - this will get the value of the env var
 * @inf: Structure containing possible arguments. Used to keep
 * constant function prototype
 * Return: the value
 */
char *_getenv(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setmyenv - will initailize a new env viriable
 * or modify an existing one
 * inf: Structure containing possible arguments. Used to keep
 * constant function prototype
 * Return: Always 0
 */

int _setmyenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetmyenv - this will remove an env variable
 * @inf: Structure contianing possible arguments. Used to keep
 * constant function prototype
 * Return: Always 0
 */
int _unsetmyenv(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("Too many arguments. \n");
		return (1);
	}
	for (i = 1; i <=inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);
	return (0);
}

/**
 * env_populate_list - This will populate env linked list
 * @inf: Structure containing possible arguments. Used to keep
 * constant function prototype
 * Return: Always 0
 */
int env_populate_list(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}
