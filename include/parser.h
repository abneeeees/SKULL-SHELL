#ifndef PARSER_H
#define PARSER_H

#include <main.h>

char *get_line(void);
char **parser(char *line);

#define SPACE " \t\a\r\n"

#endif

