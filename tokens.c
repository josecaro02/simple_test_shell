#include "shell.h"

int main(void)
{
	char str[100] = "This is www.tutorialspoint.com website";
	const char s[2] = " ";
	char *token;

	token = strtok(str, s);
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, s);
	}
	return (0);
}
