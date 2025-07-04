#include <parser.h>

void store_history(char* line){
	FILE *ptr;
	ptr = fopen("command.txt" , "a");

	if (ptr == NULL){
		perror("failed to create file");
	}

	fprintf(ptr , "%s\n" , line);
	fclose(ptr);
}
//
//void up(FILE *ptr , char *line , int count){
//	printf("%s" , line);
//	line[count++];
//}
//
//void down(FILE *ptr , char *line , int count){
//	printf("%s" , line);
//	line[count--];
//}
//
