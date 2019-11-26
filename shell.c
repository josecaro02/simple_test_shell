#include "simple_shell.h"

/**
 * main - Display prompt.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *prompt = "#cisfun$ ";
	char *salida = "exit";
	char *buffer, *token;
	size_t size = 1024;
	pid_t child;
	char *argv[256];
	int i, j;

	buffer = malloc(sizeof(char) * size);
	if (!buffer)
	{
		perror("Unable to allocate buffer");
		exit (0);
	}
	do {
		write(1, prompt, 9);
		signal(SIGINT, signalhandler);
		i = getline(&buffer, &size, stdin);
		if (_strcmp(salida, buffer) == 0)
		{
			free(buffer);
			return (0);
		}
		if (i == -1)
		{
			write(1, "\n", 1);
			free(buffer);
			return (0);
		}
		child = fork();
		if (child == -1)
		{
			perror("Error");
			return (1);
		}
		if (child == 0)
		{
			token = strtok(buffer, " \n");
			j = 0;
			while (token)
			{
				argv[j] = token;
				token = strtok(NULL, " \n");
				j++;
			}
			argv[j] = NULL;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	} while (1);
	return (0);
}
