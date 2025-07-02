CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/parser.c src/commands.c src/executer.c src/utils.c 
OBJ = $(SRC:.c=.o)
TARGET = skull

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
