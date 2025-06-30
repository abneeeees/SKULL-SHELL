#include <commands.h>
#include <parser.h>

// Initializing command functions
int cd(char **args);
int exit_shell(char **args);
int echo_commands(char **agrs);
int clear(char **args);
int pwd_shell(char **args);

char *builtin[] = {
    "cd",
    "exit",
    "echo",
    "clear",
    "pwd",
    "help",
    "alias",
    "unalias",
    "export",
    "unset",
    "read",
    "set",
    "source",
    "jobs",
    "fg",
    "bg",
    "kill",
    "wait"
};



// Array of function pointers
int (*builtin_func[])(char **) = {
    &cd,
    &exit_shell,
    &echo_commands,
    &clear,
    &pwd_shell,
};

int builtin_size(void){
    return sizeof(builtin) / sizeof(char *) ;
}