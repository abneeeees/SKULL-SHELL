#include <utils.h>
#include <commands.h>
#include <parser.h>

int cd(char **args) {
    if (args[1] == NULL) {
        printf(RED "expected argument to 'cd'\n" RESET);
    } else {
        if (chdir(args[1]) != 0) {
            printf(RED "no such file or directory\n" RESET) ;
        }
    }
    return 1;
}

//function to exit the shell
int exit_shell(char **args) {
    if (args[0] == NULL) {
        perror("No command");
    } else {
        exit(0) ; // exits the shell
    }

    return 1;
}

// function to return the current working directory
int pwd_shell(char **args) {
    char cwd[1024];

    if (args[0] == NULL) { // if command given is wrong or null prints wrong command
        perror("No command");
    } else {
        //calling getcwd() function that gives current working directory 
        getcwd(cwd, sizeof(cwd)); 
        // printing current working directory
        printf(MAGENTA "%s'\n" RESET , cwd );
    }

    return 1;
}

// clears console
int clear(char **args) {
    if (args[0] == NULL) {
        perror("No command");
    } else {
        // Clear screen and move cursor to top-left
        printf("\033[H\033[J");
        fflush(stdout);
    }
    return 1;
}

// prints something on the screen of terminal (eg : echo your_command) -> your_command
int echo_commands(char **args) {
    if (args[0] == NULL) {
        perror("No command");
    } else{
        int i=1;
        while(args[i] != NULL){
            printf(MAGENTA "%s " RESET , args[i]) ;
            i++ ;
        }
        printf("\n") ;
    }
return 1;
}
