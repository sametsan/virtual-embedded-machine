CC=gcc
TARGET=program

SRC=$(wildcard ./*.c)

OBJ=$(SRC:.c=.o)

FLAGS= -I.

all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $^ $(FLAGS) -o $@

%.o:%.c
	$(CC) $< -c -o $@


clean:
	rm -f $(OBJ)