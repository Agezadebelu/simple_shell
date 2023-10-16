#include "shell.h"

/**
 * ctrlC - to execute the ctrl + c signal
 *
 * @sig_num: the signal sent if we touch Ctrl+C
 **/

void hsh_ctrlC(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
