#include <commands.h>
#include <parser.h>

// Initializing command functions
int cd(char **args);
int exit_shell(char **args);
int echo_commands(char **agrs);
int clear(char **args);
int pwd_shell(char **args);
int alias(char **args);

char *builtin[] = {
    "cd",
    "exit",
    "echo",
    "clear",
    "pwd",
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
    "wait",
};

char *builtin_helps[] = {
    // cd
    "cd: change the shell working directory\n"
    "Usage: cd [directory]\n"
    "If no directory is given, changes to the HOME directory.",

    // exit
    "exit: exit the shell\n"
    "Usage: exit [status]\n"
    "Exit the shell with a status of N. If N is omitted, the exit status is that of the last command executed.",

    // echo
    "echo: display a line of text\n"
    "Usage: echo [options] [string ...]\n"
    "Options:\n"
    "  -n        do not output the trailing newline",

    // clear
    "clear: clear the terminal screen\n"
    "Usage: clear [options]\n"
    "Options:\n"
    "  -T TERM     use this instead of $TERM\n"
    "  -V          print curses-version\n"
    "  -x          do not try to clear scrollback",

    // pwd
    "pwd: print name of current working directory\n"
    "Usage: pwd",

    // help
    "help: display information about builtin commands\n"
    "Usage: help [command]",

    // alias
    "alias: define or display aliases\n"
    "Usage: alias [name[='value'] ...]",

    // unalias
    "unalias: remove alias definitions\n"
    "Usage: unalias name",

    // export
    "export: set environment variables\n"
    "Usage: export [name[=value] ...]",

    // unset
    "unset: unset values and attributes of shell variables\n"
    "Usage: unset [name]",

    // read
    "read: read a line from standard input\n"
    "Usage: read [variable]",

    // set
    "set: set shell options\n"
    "Usage: set [--abefhkmnptuvxBCEHPT] [arg ...]",

    // source
    "source: execute commands from a file in the current shell\n"
    "Usage: source filename",

    // jobs
    "jobs: list active jobs\n"
    "Usage: jobs",

    // fg
    "fg: resume a job in the foreground\n"
    "Usage: fg [job_spec]",

    // bg
    "bg: resume a job in the background\n"
    "Usage: bg [job_spec]",

    // kill
    "kill: terminate a process\n"
    "Usage: kill [-s signal | -p] [pid ...]",

    // wait
    "wait: wait for processes to complete\n"
    "Usage: wait [pid]"
};


// Array of function pointers
int (*builtin_func[])(char **) = {
    &cd,
    &exit_shell,
    &echo_commands,
    &clear,
    &pwd_shell,
    &alias
};

int builtin_size(void){
    return sizeof(builtin) / sizeof(char *) ;
}

