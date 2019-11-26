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
int _which(char *s);
void signalhandler();

#endif /* SIMPLE_SHELL_H */
