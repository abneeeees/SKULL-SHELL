#include <executer.h>
#include <commands.h>
#include <parser.h>

int checking_fork(char **args)
{
    pid_t pid = fork();
    int status;

    if (pid < 0 ){
    printf("failed to fork");
    exit (0) ;
    } else if ( pid == 0){
    //child process
    if (execvp(args[0] , args) == -1){
        // Command not found in built-ins or external
        printf(RED "Error: wrong command\n" RESET);
    } 
    } else if (pid >0){
        // Parent waits
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            return 0; 
        } else {
            return 1; 
        }
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
        // Compare first argument to built-in keywords
        // strcmp(str1, str2) == 0 means strings are equal

        if (strcmp(args[0], builtin[i]) == 0 && args[1]!=NULL && strcmp(args[1], "-h")==0) {
            printf("/n%s/n" , builtin_helps[i]);
        } else if (strcmp(args[0] , builtin[i])==0){
            return builtin_func[i](args);
        }
    }

    // If we've reached the last builtin and no match, try external
    if (checking_fork(args) == 0) {
        return 1; // exits
    }

    return 1;
}



