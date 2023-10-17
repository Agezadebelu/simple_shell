#include "shell.h"

void change_directory(const char *directory) 
{
    if (directory == NULL || _strcmp(directory, "") == 0) 
    {
        // No argument given, interpret it as cd $HOME
        directory = _getenv("HOME");
    } else if (_strcmp(directory, "-") == 0) 
    {
        // Special case: cd -
        directory = _getenv("OLDPWD");
    }

    // Get the current working directory before changing it
    char *old_directory = getcwd(NULL, 0);
    
    if (chdir(directory) != 0) 
    {
        perror("cd");
    } else 
    {
        // Update the PWD environment variable
        if (_setenv("PWD", getcwd(NULL, 0), 1) != 0) 
	{
            perror("setenv");
        }
    }

    free(old_directory);
}
