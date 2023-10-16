#include "shell.h"
/**
 * main - main entry point
 *
 * Return: Always 0.
 **/

int main(void)
{
	int read = 0, loop = 0, exitstat = 0;
	size_t size = 0;
	char *str_line = NULL;
	char **args = NULL;

	while (loop == 0)
	{
		signal(SIGINT, hsh_ctrlC);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&str_line, &size, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (hsh_breakline(str_line) == 0)
			continue;
		args = hsh_stringtok(str_line, " \t\n");
		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exitstat = exit_status(args);
				if (exitstat == 2)
					continue;
				free(str_line);
				exit(exitstat);
			}
			if (hsh_builtin(args) == 1)
				continue;
			hsh_execarg(args);
			free(args);
		}
		else
			free(args);
	}
	free(str_line);
	return (0);
}
