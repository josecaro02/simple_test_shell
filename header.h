#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int _putchar(char c);
void print_number(int n);
int _strlen_recursion(char *s);
int _atoi(char *s);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

void path(char **argv);
void _env(void);
char *_getenv(char *var);


#endif /* HEADER_H */
