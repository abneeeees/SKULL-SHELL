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
//
//    FILE *ptr = fopen("commands.txt" , "r+");
//    if (!ptr){perror("failed opening the file");}
//    char *line = NULL;
//    size_t len=0;
//    int count=0;


    do {
        char *username = getenv("USER");  //getting username of device
        char cd[1024];
        getcwd(cd, sizeof(cd));  // getting current directory of device


        printf( YELLOW "%s " RESET , username  ); // printing username / current directory
        printf(MAGENTA"[ %s ] " RESET , cd);
        printf(GREEN">> "RESET);

        sentc = get_line();
        args = parser(sentc);
        status = commd_execute(args);
//
//	while(getline(&line , &len , ptr) != -1){
//		if(strcmp(args[0] , "up") == 0){
//			up(ptr , line , count);
//		}
//		if(strcmp(args[0] , "down") == 0){
//			down(ptr , line , count);
//		}

//	}
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
