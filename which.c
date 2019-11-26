#include "simple_shell.h"

/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *d1 = "/bin/";
	char *d2 = "/usr/bin/";
	char *d3 = "/sbin/";
	char *i1, *i2, *i3;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		i1 = str_concat(d1, av[i]);
		i2 = str_concat(d2, av[i]);
		i3 = str_concat(d3, av[i]);
		if (stat(i1, &st) == 0)
		{
			printf("%s\n", i1);
		}
		else if (stat(i2, &st) == 0)
		{
			printf("%s\n", i2);
		}
		else if (stat(i3, &st) == 0)
		{
			printf("%s\n", i3);
		}
		else
		{
			printf("NOT FOUND\n");
			return (1);
		}
		i++;
	}
	return (0);
}
