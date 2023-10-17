#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

void hsh_execarg(char **args);
char **hsh_stringtok(char *str_line, const char *delimitator);
char *_which(char **args);
char *hsh_iscommand(char **args);
void hsh_printenv(void);
extern char **environ;
void hsh_ctrlC(int sig_num);
int hsh_breakline(char *str_line);
int _atoi(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(char *str);
void hsh_cd(const char *directory);
int exit_status(char **args);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int overwrite_env(const char *name, const char *value);
int hsh_builtin(char **args);

#endif
