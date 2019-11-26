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

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);

int _which(char *s);
void signalhandler();
char *path(char **argv);
int _env(void);

#endif /* SIMPLE_SHELL_H */
