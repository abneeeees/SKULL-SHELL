#include <parser.h>
#include <commands.h>
#include <executer.h>
#include <utils.h>


void main_loop(void) {
    // initializing variable pointers
    char *line;
    char **args;
    int status = 1;

    do {
        printf("> ");
        char* username = getenv("USER");  //getting username of device
        char cd[1024];
        getcwd(cd , sizeof(cd));  // getting current directory of device


        printf("%s " , username  ); // printing username / current directory

        line = get_line();
        args = parser(line);
        status = commd_execute(args);

        // freeing the dynamically allocated memory from get_line function and parser function
        free(line);
        free(args);
    } while (status);
}


int main() {
    // calling the main loop
    main_loop();
    return 0;
}
