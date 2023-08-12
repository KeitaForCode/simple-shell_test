#include "shell.h"
/**
 * interative - this wil return true if shell is in interactive mode
 * @inf: the address of struct
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interractive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <=2);
}

/**
 * is_delim - will check if character is a delimeter
 * @chr: the character to be checked
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char chr, char *delim)
{
	while (*delim)
		if (*delim++ == chr)
			return (1);
	return (0);
}

/**
 * _isalpha - will check for alphabetic characters
 * @chr: The character to be inputed
 * Return: 1 if chr is alphabet, 0 otherwise
 */
int _isalpha(int chr)
{
	if ((chr >='a' && chr <='z') || (chr >='A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - This will convert string to an integer
 * @str: The string to be converted
 * Return: 0 if no numbers in string, otherwise converted number
 */
int _atoi(char *str)
{
	int i, output, sign = 1, flag = 0;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -reuslt;
	else
		output = result;

	return (output)
}
