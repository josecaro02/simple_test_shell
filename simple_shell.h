#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

void signalhandler();
void path(char **argv);
void _env(void);
char *_getenv(char *var);

#endif /* SIMPLE_SHELL_H */
