#include "shell.h"

/**
 * hsh_cd - changes the current working directory of the hsh.
 * @args: array of arguments string.
 *
 * Return: On success, zero is returned.  On error, -1 is returned.
 */

void hsh_cd(char *directory) 
{
	char *old_directory;
	if (directory == NULL || _strcmp(directory, "") == 0)
	{
		directory = _getenv("HOME");
	}
	else if (_strcmp(directory, "-") == 0)
	{
		directory = _getenv("OLDPWD");
	}
	
	old_directory = getcwd(NULL, 0);
	if (chdir(directory) != 0)
	{
		perror("cd");
	}
	else
	{
		if (_setenv("PWD", getcwd(NULL, 0), 1) != 0)
			perror("setenv");
        }
	free(old_directory);
}
