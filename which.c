#include "simple_shell.h"

/**
 * str_concat - Function that concatenates two strings with malloc.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: Array.
 */

char *str_concat(char *s1, char *s2)
{
	char *array;
	int size1, size2, i;

	if (!s1)
		size1 = 0;
	else
	{
		for (size1 = 0; s1[size1]; size1++)
		{}
	}
	if (!s2)
		size2 = 0;
	else
	{
		for (size2 = 0; s2[size2]; size2++)
		{}
	}
	array = malloc((size1 + size2 + 1) *  sizeof(char));
	if (!array)
		return (0);
	for (i = 0; i < (size1 + size2); i++)
	{
		if (i < size1)
		{
			array[i] = *s1;
			s1++;
		}
		else if (i < (size1 + size2))
		{
			array[i] = *s2;
			s2++;
		}
	}
	array[i] = '\0';
	return (array);
}

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
