#include "shell.h"

/**
  * hsh_stringtok - spliting user input into arguments.
  * @str_line: string to be tokens.
  * @delimitator: separator used to token.
  * Return: null or array pointers to the tokenes.
**/

char **hsh_stringtok(char *str_line, const char *delimitator)
{
	char *token = NULL;
	int j = 0, i = 0;
	char **args;

	while (str_line[i] != '\0')
	{
		if (str_line[i] != 32 && str_line[i] != 10
				       && str_line[i] != 58 && str_line[i] != 9)
		{
			while (str_line[i] != 32 && str_line[i] != 10 && str_line[i] != 9
					&& str_line[i] != 58 && str_line[i] != '\0')
			{
				i++;
			}
			j++;
		}
		if (str_line[i] == '\0')
		{
			break;
		}
		i++;
	}
	args = malloc(sizeof(char *) * (j + 1));
	if (args == NULL)
	{
		return (NULL);
	}
	i = 0;
	token = strtok(str_line, delimitator);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delimitator);
		i++;
	}
	args[i] = NULL;
	return (args);
}
