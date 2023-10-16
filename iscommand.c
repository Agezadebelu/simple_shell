#include "shell.h"

/**
 * hsh_iscommand - check the input file in the path is an executable file.
 * @args: arrays of arguments obtained from the tokenized string input.
 * Return: return full path on secesuss or NULL otherwise.
**/

char *hsh_iscommand(char **args)
{
	int i = 0, j = 0;
	char *str_path = NULL, *file_path = NULL;
	char **path = NULL;
	struct stat st;

	str_path = _getenv("PATH");
	path = hsh_stringtok(str_path, ":");
	while (path[j] != NULL)
	{
		file_path = calloc(3, (sizeof(char) *
		((_strlen(path[j])) + (_strlen(args[i])) + 2)));
		if (file_path == NULL)
		{
			free(path);
			free(str_path);
			return (NULL);
		}
		_strcat(file_path, path[j]);
		_strcat(file_path, "/");
		_strcat(file_path, args[i]);
		if (stat(file_path, &st) == 0)
		{
			free(path);
			free(str_path);
			return (file_path);
		}
		j++;
	free(file_path);
	}
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(str_path);
	free(path);
	return (NULL);
}
