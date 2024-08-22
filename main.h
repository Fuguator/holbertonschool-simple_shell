#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

char **divider(char *buffer, char **arr);
char *_getline(void);
void _exec(char *buffer, char **argv);
void find_path(char *buffer, char **argv);
int handle_path(char *buffer);
void print_env(char *buffer);
#endif
