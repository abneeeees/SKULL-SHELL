#ifndef UTILS_H
#define UTILS_H

#include <main.h>
#include <dirent.h>
#include <termios.h>


int cd(char **args);
int exit_shell(char **args);
int pwd_shell(char **args);
int clear(char **args);
int echo_commands(char **args);

#endif 
