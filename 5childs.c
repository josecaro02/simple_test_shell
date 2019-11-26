#include "shell.h"

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */

int main(void)
{
	unsigned int i;
	pid_t child;
	char *argv[] = {"/bin/ls", "-l", "..", NULL};

	i = 0;
	while (i < 5)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child == 0)
		{
			printf("PID %d & PPID %d\n", getpid(), getppid());
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			exit(0);
		}
		else
		{
			wait(NULL);
		}
		i++;
	}
	return (0);
}
