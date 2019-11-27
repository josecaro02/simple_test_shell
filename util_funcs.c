#include "header.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *print_number - print any number with putchar
 *@n: number given by user
 *
 *Return: no return it is a void
 */

void print_number(int n)
{
	unsigned int digito, res_digito, i, nro;

	n < 0 ? _putchar('-') : 1;
	n = (n < 0) ? n * -1 : n * 1;
	nro = n;
	res_digito = nro;
	digito = 1;
	while (res_digito >= 10)
	{
		digito = digito * 10;
		res_digito = nro / digito;
	}
	nro = n;
	for (i = digito; i >= 1; i = i / 10)
	{
		_putchar(nro / i + '0');
		nro = nro % i;
	}
}

/**
 *_strlen_recursion - calculate the lenght of a recursion
 *@s: string given by user
 *
 *Return: lenght of recursion
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));

}

/**
 *_atoi - convert a string to an integer.
 *@s: string given by user
 *
 *Return: int with the number of the string
 */
int _atoi(char *s)
{
	unsigned int dig_n;
	int sign, var_dig, var_salida;
	char cara;

	dig_n = 0;
	sign = 1;
	var_dig = 0;
	var_salida = 0;
	while (*s != '\0')
	{
		cara = *s;
		if (cara == '-')
			sign = sign * -1;
		if ((cara >= '0') && (cara <= '9'))
		{
			dig_n = dig_n * 10 + cara - '0';
			var_dig = 1;
			var_salida = 1;
		}
		else
			var_salida = 0;
		if (var_dig == 1 && var_salida == 0)
			break;
		s++;
	}
	return (dig_n * sign);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: Comparation.
 */
int _strcmp(char *s1, char *s2)
{
       int compare, i;
       for (i = 0; s2[i] != '\0'; i++)
       {
	       compare = s1[i] - s2[i];
               if (compare != 0)
                       break;
       }
       return (compare);
}
