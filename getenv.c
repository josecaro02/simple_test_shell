#include "simple_shell.h"

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

extern char **environ;

char *_getenv(char *var)
{
	char *token;
	int i;

	i = 0;
	while (environ[i])
	{
		if (_strcmp(var, environ[i]) == 0)
		{
			token = _strstr(environ[i], var);
			if (token[0] == '=')
			{
				token = _strchr(environ[i], '=');
				return (token);
			}
		}
		i++;
	}
	return (0);
}

int main(void)
{
	char *path;
	char *variable = "PATH";
	int i;

	i = _env();
	path = _getenv(variable);

	printf("-----------\n%s\n----------\n", path);
	i = _env();
	return (0);
}
