#include "header.h"

/**
* signalhandler - Ignore CTRL + C.
*
* Return: Nothing.
*/
void signalhandler(__attribute__((unused))int s)
{
	char *prompt = "\n#cisfun$ ";

	write(1, prompt, 10);
}

int exit_func(char **argv, int h_command, char *argum, int exit_s, char **b)
{
	char *salida;
	int num_exit;
	char *text = ": exit: Illegal number: ";
	char *text2 = "\n";
	char *text3 = ": ";

	salida = "exit\n";
	if (_strcmp(salida, argv[0]) == 0)
	{
		if (argv[1] != NULL)
		{
			num_exit = _atoi(argv[1]);
			if (num_exit < 0)
			{
				write(1, argum, _strlen_recursion(argum));
				write(1, text3, 2);
				print_number(h_command);
				write(1, text, _strlen_recursion(text));
				write(1, argv[1], _strlen_recursion(argv[1]));
				write(1, text2, 1);
				return (2);
			}
			else if (num_exit <= 255)
			{
				free(*b);
				exit(num_exit);
			}
			else
			{
				free(*b);
				exit(num_exit % 255);
			}

		}
		free(*b);
		exit(exit_s);
	}
	return (-1);
}

void excess_argv(char *argv0, char *argv1)
{
	char *text = ": 0: Can't open ";
	char *text2 = "\n";

	write(1, argv0, _strlen_recursion(argv0));
	write(1, text, _strlen_recursion(text));
	write(1, argv1, _strlen_recursion(argv1));
	write(1, text2, 1);
	exit(127);
}

int  main(int argc, char *argum[])
{
	char *prompt = "#cisfun$ ", *argv[256], *buffer, *token;
	size_t bufsize = 1024;
	int i = 0, characters, h_command = 0, ex_s = 0;

	if (argc > 1)
		excess_argv(argum[0], argum[1]);
	while (1)
	{
		h_command++;
		if (isatty(fileno(stdin)) == 1)
			write(1, prompt, 9);
		signal(SIGINT, signalhandler);
		characters = getline(&buffer, &bufsize, stdin);
		argv[0] = token = strtok(buffer, " \n\t");
		for (i = 1; (token = strtok(NULL, " \n\t")); i++)
			argv[i] = token;
		argv[i] = NULL;
		if (characters == -1)
		{
			if (isatty(fileno(stdin)) == 1)
				write(1, "\n", 1);
			free(buffer);
			return (0);
		}
		if ((ex_s = (exit_func(argv, h_command, argum[0], ex_s, &buffer))) == 2)
			continue;
		if (fork() == 0)
		{
			if (argv[0][0] != '.')
				path(&argv[0]);
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			kill(getpid(), SIGKILL);
		}
		else
			wait(NULL);
		i = 0;
	}
	return (0);
}
