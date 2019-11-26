#include "simple_shell.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: Comparation.
 */

int _strcmp(char *s1, char *s2)
{
        int i;

        i = 0;
        while (s1[i])
        {
                if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
                {
                        return (s1[i] - s2[i]);
                }
                i++;
        }
        return (0);
}

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
			token = strtok(environ[i], "=");
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	return (0);
}

int main(void)
{
	char *path;
	char *variable = "PATH";

	path = _getenv(variable);
	printf("%s\n", path);
	return (0);
}
