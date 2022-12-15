CC=gcc
FLAGS=

OBJ= main.o ft_mat.o ft_mem.o

%.o: %.c %.h
	$(CC) $(FLAGS) $< -c -o $@

projet: $(OBJ)
	$(CC) $^ -o $@

.PHONY: run clean

clean:
	rm -f *.o *~ core
