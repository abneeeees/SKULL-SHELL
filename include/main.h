#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define GRAY    "\x1b[30m"
#define RESET   "\x1b[0m"

#define red()     printf("\033[1;31m")
#define green()   printf("\033[1;32m")
#define yellow()  printf("\033[1;33m")
#define blue()    printf("\033[1;34m")
#define magenta() printf("\033[1;35m")
#define cyan()    printf("\033[1;36m")
#define gray()    printf("\033[1;30m")  // Bright black = gray
#define reset()   printf("\033[0m")

 
#endif