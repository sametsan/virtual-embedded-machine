CC=gcc
TRGT_SIM=simulator
TRGT_PRG=program

SRC=$(wildcard lib/*.c)

OBJ_PRG=$(SRC:.c=.o) program.o
OBJ_SIM=$(SRC:.c=.o) simulator.o

FLAGS= -I. -pthread -I./lib/

all: $(TRGT_SIM) $(TRGT_PRG)


$(TRGT_PRG): $(OBJ_PRG)
	$(CC) $^ $(FLAGS) -o $@

$(TRGT_SIM): $(OBJ_SIM)
	$(CC) $^ $(FLAGS) -o $@

%.o:%.c
	$(CC) $< -c  $(FLAGS) -o $@

clean:
	rm -f $(OBJ_PRG)
	rm -f $(OBJ_SIM)
	rm -f $(TRGT_SIM)
	rm -f $(TRGT_PRG)
	