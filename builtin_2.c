#include "shell.h"
/**
 * _hsitory_list - this will displays the history list, one command by line,
 * proceded with line numbers, starting at 0.
 * @inf: Structure containing arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0.
 */
int _history_list(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * alias_unset - this will set alias to string
 * @inf: Parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_unset(info_t *inf, char *str)
{
	char *p, c;
	int ret;

	p = strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_set - this will set the alias to the string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_set(info_t *inf, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alias_unset(inf, str));
	alias_unset(inf, str);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * alias_print - this will print an alias string
 * @node: alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_print(list_t *node)
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
 * _myalias - this will imitate the builtin alias
 * @inf: Structure containing possible arguments. Used to keep
 * constant function prototype
 * Return: Always 0
 */
int _myalias(info_t *inf)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			alias_print(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		p = _strchr(inf->argv[i], '=');
		if (p)
			alias_set(inf, inf->argv[i]);
		else
			alias_print(node_starts_with(inf->alias, inf->argv[i], '='));
	}
	
	return (0);
}

