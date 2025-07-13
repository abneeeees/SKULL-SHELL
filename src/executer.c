#include <executer.h>
#include <commands.h>
#include <parser.h>

int checking_fork(char **args){
    pid_t pid = fork();
    int status;

    if (pid < 0 ){
        printf("failed to fork");
        exit (0) ;
    } else if ( pid == 0){
    //child process
    if (execvp(args[0] , args) == -1){
        // Command not found in built-ins or external
        printf(RED " Error: wrong command\n" RESET);}
    } else if (pid >0){
        // Parent waits
        waitpid(pid, &status, 0);
            return 1;
        }

    return 1;

}


// Main function that executes commands
int commd_execute(char **args) {
    if (args[0] == NULL) {
        // Empty command was passed
        return 1;
    }

    // Loop through all built-in commands
    for (int i = 0; i < builtin_size(); i++) {
        if(strcmp(builtin[i] , args[0])==0){
            if(builtin_func[i] != NULL){
                return builtin_func[i](args);
            } else {
                printf(RED "command %s not implemented yet" RESET , args[0]);
                return 1;
            }
        }
    }

    // If we've reached the last builtin and no match, try external
    return checking_fork(args);
}



