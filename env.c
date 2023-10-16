#include "shell.h"

/**
 * _getenv - check the environment list to find variable "str".
 * @str: enviroment variable name used to search. M.A.E.S.
 * Return: the environment variable, or NULL if it doesn't exist.
 **/

char *_getenv(char *str)
{
	unsigned int i = 0, j = 0, k = 0, lenvar = 0, lenenv = 0;
	char *envvar = NULL, *envval = NULL;

	if (str != NULL)
	{
		lenvar = _strlen(str);
		while (environ[i] != NULL)
		{
			lenenv = _strlen(environ[i]);
			envvar = malloc(sizeof(char) * (lenvar + 1));
			if (envvar == NULL)
				return (NULL);
			envval = malloc(sizeof(char) * (lenenv - 1 - lenvar + 1));
			if (envval == NULL)
			{
				free(envvar);
				return (NULL);
			}
			j = 0;
			while (j < lenvar)
			{
				envvar[j] = environ[i][j], j++;
			}
			envvar[j] = '\0';
			if (_strcmp(str, envvar) == 0)
			{
				j++;
				while (environ[i][j])
				{
					envval[k] = environ[i][j];
					j++, k++;
				}
				envval[k] = '\0', free(envvar);
				return (envval);
			}
			free(envval), free(envvar);
		i++;
		}
	}
	return (NULL);
}

/**
 * printenv - prints(display) the environment variables list.
 **/

void hsh_printenv(void)
{
	int j = 0;

	while (environ[j] != NULL)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
 * _setenv - set a new environment variable, or modify an existing
 * usage setenv VARIABLE VALUE.
 * @name: enviroment variable name to initialize.
 * @value: variable value.
 * @overwrite: 1 - if the variable already exist overwrite its value, 0 if don't.
 * Return: 0 returned if function succes -1 if it failure.
 **/

int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int i = 0, lenname = 0, lenvalue = 0;
	char *getenv = NULL;

	getenv = _getenv((char *)name);
	if (getenv == NULL)
	{
		lenname = _strlen((char *)name);
		lenvalue = _strlen((char *)value);
		while (environ[i] != NULL)
		{
			i++;
		}
		environ[i] = malloc(sizeof(char) * (lenname + 1 + lenvalue + 1));
		if (environ[i] == NULL)
			return (-1);
		environ[i] = _strcat((char *)name, "=");
		environ[i] = _strcat(environ[i], (char *)value);
		i++;
		environ[i] = NULL;
		return (0);
	}
	else
	{
		if (overwrite == 1)
		{
			free(getenv);
			return (overwrite_env(name, value));
		}
		else
			return (0);
	}
}

/**
 * overwrite_env - an existent enviroment variable value is modifyed.
 * @name: enviroment variable to initialize.
 * @value: variable vaue.
 * Return: 0 returned if function succes -1 if it failure.
 **/

int overwrite_env(const char *name, const char *value)
{
	unsigned int i = 0, j = 0, lenvar = 0, lenenv = 0;
	char *envvar = NULL;

	if (name != NULL && value != NULL)
	{
		lenvar = _strlen((char *)name);
		while (environ[i] != NULL)
		{
			lenenv = _strlen((char *)value);
			envvar = malloc(sizeof(char) * (lenvar + 1));
			if (envvar == NULL)
				return (-1);
			j = 0;
			while (j < lenvar)
			{
				envvar[j] = environ[i][j], j++;
			}
			envvar[j] = '\0';
			if (_strcmp((char *)name, envvar) == 0)
			{
				environ[i] = calloc(1, (sizeof(char) * (lenvar + 1 + lenenv + 1)));
				if (environ[i] == NULL)
				{
					free(envvar);
					return (-1);
				}
				_strcat(environ[i], envvar);
				_strcat(environ[i], "=");
				_strcat(environ[i], (char *)value);
				free(envvar);
				return (0);
			}
			free(envvar);
		i++;
		}
	}
	return (-1);
}
