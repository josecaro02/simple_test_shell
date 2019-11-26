#include "simple_shell.h"

/**
 * path - Find command path.
 *
 * Return: A pointer created with malloc.
 */

char *path(char **argv)
{
	struct stat st;
	char *slsh = "/";
	char *env_path, *command, *token, *path;

	if (argv[0][0] == '/')
	{
		return (argv[0]);
	}
	env_path = _getenv("PATH");
	command = str_concat(slsh, argv[0]);
	token = strtok(env_path, ":");
	while (token)
	{
		path = str_concat(token, command);
		if (stat(path, &st) == 0)
		{
			break;
		}
		token = strtok(NULL, ":");
	}
	free(command);
	return (path);
}

int main
