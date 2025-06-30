#ifndef EXECUTER_H
#define EXECUTER_H

#include <main.h>
#include <sys/wait.h>

int checking_fork(char **args);
int commd_execute(char **args);


#endif