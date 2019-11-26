#include "simple_shell.h"

extern char **environ;

int _env(void)
{
	char **ep;

	ep = environ;
	while (*ep)
	{
		puts(*ep);
		ep++;
	}
	return (0);
}

int main(void)
{
	int i;

	i = _env();
	return (i);
}
