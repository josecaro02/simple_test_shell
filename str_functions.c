#include "header.h"

/**
 * _strlen - Returns the length of a string.
 * @s: String.
 *
 * Return: Length of s.
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * str_concat - Function that concatenates two strings with malloc.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: New string.
 */

char *str_concat(char *s1, char *s2)
{
        char *array;
        int size1 = 0, size2 = 0, i = 0;

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
 * _strstr - Function that locates a substring.
 * @haystack: Variable.
 * @needle: Variable.
 *
 * Return: haystack.
 */

char *_strstr(char *haystack, char *needle)
{
	int x;
	int y;

	x = 0;
	while (haystack[x])
	{
		y = 0;
		while (needle[y])
		{
			if (haystack[x + y] != needle[y])
			{
				break;
			}
			y++;
		}
		if (!needle[y])
		{
			return (haystack + x + y);
		}
		x++;
	}
	return (0);
}

/**
 * _strchr - Function that locates a character in a string.
 * @s: Variable.
 * @c: Variable.
 *
 * Return: *s.
 */

char *_strchr(char *s, char c)
{
	int x;

	x = 0;
	while (s[x] != c && s[x] != '\0')
	{
		x++;
	}
	if (s[x] == '\0' && s[x] != c)
	{
		return (0);
	}
	return (s + x + 1);
}
