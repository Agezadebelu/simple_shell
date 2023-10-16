#include "shell.h"
/**
 * exit_status - exit with status.
 * @args: status in string to be changed to an integer.
 * Return: -1 if status is not correct number 0 otherwise.
 */

int exit_status(char **args)
{
	int exitstat = 0, k = 0;

	if (args[1] != NULL)
	{
		exitstat = _atoi(args[1]);

		while (args[1][k] != '\0')
		{
			if (args[1][k] < '0' || args[1][k] > '9')
			{
				write(STDOUT_FILENO, args[0], _strlen(args[0]));
				write(STDOUT_FILENO, ": Illegal number: ", 19);
				write(STDOUT_FILENO, args[1], _strlen(args[1]));
				write(STDOUT_FILENO, "\n", 1);
				free(args);
				return (2);
			}
		k++;
		}
		free(args);
		return (exitstat);
	}
	else
	{
		exitstat = EXIT_SUCCESS;
		free(args);
		return (exitstat);
	}
}
