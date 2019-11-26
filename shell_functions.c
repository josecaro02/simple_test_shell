#include "simple_shell.c"

/**
 * singnalhandler - Ignore CTRL + C.
 *
 * Return: Nothing.
 */

void signalhandler()
{
        write(1, "\n#cisfun$ ", 10);
}
