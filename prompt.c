#include "shell.h"

/**
 * main - Display prompt.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *prompt = "$ ";
	char *buffer;
	size_t size = 1024;
	int i, j;

	buffer = malloc(size);
	if (!buffer)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	write(1, prompt, 2);
	i = getline(&buffer, &size, stdin);
	if (i == -1)
	{
		write(1, "\n", 1);
		free(buffer);
		return (-1);
	}
	j = _strlen(buffer);
	write(1, buffer, j);
	write(1, "\n", 1);
	free(buffer);
	return (0);
}
