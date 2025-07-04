#include <parser.h>
#include <memory.h>

char *get_line(void) {
    int buffer_size = 1024;
    int position = 0;

    // allocating memory dynamically
    char *buffer = malloc(buffer_size);

    if (!buffer) {
        fprintf(stderr, "allocation error\n");  // If buffer is NULL, print error to stderr
        exit(EXIT_FAILURE);                     // Exit program with error status (1)
    }

    int c;
    while (1) {
        cyan();
        c = getchar();  // Reads one character or EOF (-1)
        reset();

        if (c == EOF || c == '\n') {           // If end of input or new line
            buffer[position] = '\0';           // Null-terminate the string
            store_history(buffer);
            return buffer;
        } else {
            buffer[position] = c;              // Store the character in buffer
        }

        position++;

        if (position >= buffer_size) {         // If buffer is full, resize it
            buffer_size += 100;
            buffer = realloc(buffer, buffer_size);  // Reallocate more memory
            if (!buffer) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Tokens are the words extracted from the command entered in the shell (via get_line())

char **parser(char *buffer) {
    int max_arg_size = 64;
    int position = 0;

    char **tokens = malloc(max_arg_size * sizeof(char*));  // Allocate memory for array of tokens
    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(buffer, SPACE);  // Split buffer into tokens based on SPACE

    while (token != NULL) {
        tokens[position] = token;  // Store token in array
        position++;

        if (position >= max_arg_size) {   // Resize if too many tokens
            max_arg_size += 64;
            tokens = realloc(tokens, max_arg_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, SPACE);  // Continue tokenizing the rest of the buffer
    }

    tokens[position] = NULL;  // tells array of token has ended
    return tokens;
}
