#include <parser.h>

void store_history(char* line){
	FILE *ptr;
	ptr = fopen("../history.txt" , "a");

	if (ptr == NULL){
		perror("failed to create file");
	}

	fprintf(ptr , "%s\n" , line);
	fclose(ptr);

}


