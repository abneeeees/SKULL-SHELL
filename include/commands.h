#ifndef COMMANDS_H
#define COMMANDS_H

#include <main.h>

int cd(char **args);
int exit_shell(char **args);
int echo_commands(char **agrs);
int clear(char **args);
int pwd_shell(char **args);

extern char *builtin[] ;
extern int (*builtin_func[])(char**);

int builtin_size(void);

#endif
