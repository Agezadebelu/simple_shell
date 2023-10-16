#include "shell.h"

/**
 * hsh_breakline - check for breaklines.
 *
 * @str_line: inputed string.
 * Return: 0 returned if string contains breaklines, 1 otherwise.
 **/

int hsh_breakline(char *str_line)
{
	int j = 0;

	while (str_line[j] != '\0')
	{
		if (str_line[j] != 10)
		{
			return (1);
		}
		j++;
	}
	return (0);
}
