#include "simple_shell.h"

/**
 * path - Find command path.
 *
 * Return: A pointer created with malloc.
 */

void path(char **argv)
{
	struct stat st;
	char *slsh = "/";
	char *env_path, *command, *token, *path;

	env_path = _getenv("PATH");
	command = str_concat(slsh, argv[0]);
	token = strtok(env_path, ":");
	while (token)
	{
		path = str_concat(token, command);
		if (stat(path, &st) == 0)
		{
			argv[0] = path;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(command);
	return (path);
}
