#include <parser.h>
#include <commands.h>
#include <executer.h>
#include <utils.h>
#include <memory.h>

void main_loop(void) {
    // initializing variable pointers
    char *sentc;
    char **args;
    int status = 1;

    do {
        time_t now = time(NULL);         // Get current time
        struct tm *t = localtime(&now);  // Convert to local time structure

        // printf("Year: %d\n", t->tm_year + 1900);  // Add 1900 to get the actual year
        // printf("Month: %d\n", t->tm_mon + 1);     // Months are numbered from 0 to 11, so add 1 to match real month numbers (1-12)
        // printf("Day: %d\n", t->tm_mday);
        char *username = getenv("USER");  //getting username of device
        char cd[1024];
        getcwd(cd, sizeof(cd));  // getting current directory of device


        printf(MAGENTA" [ %s ] " RESET , cd);
        printf(CYAN "[   %d : " , t->tm_hour);
        printf(CYAN "%d | " , t->tm_min);
        printf(CYAN "%d / ", t->tm_mon + 1);     // Months are numbered from 0 to 11, so add 1 to match real month numbers (1-12)
        printf(CYAN "%d ]\n" RESET, t->tm_mday);
        printf( YELLOW " %s " RESET , username  ); // printing username / current directory
        printf(GREEN">> "RESET);

        sentc = get_line();
        args = parser(sentc);
        status = commd_execute(args);
        // freeing the dynamically allocated memory from get_line function and parser function
        free(sentc);
        free(args);
    } while (status);
}

int main() {
    // calling the main loop

    main_loop();
    return 0;
}
