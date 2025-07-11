#ifndef COMMANDS_H
#define COMMANDS_H

#include <main.h>

int cd(char **args);
int exit_shell(char **args);
int echo_commands(char **args);
int clear(char **args);
int pwd_shell(char **args);

extern char *builtin[] ;
extern int (*builtin_func[])(char**);
extern char *builtin_helps[];

int builtin_size(void);

#endif
