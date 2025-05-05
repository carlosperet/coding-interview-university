CC = clang
CFLAGS = -Wall -Wextra -std=c11
OBJ = hash_table.o
DEPS = hash_table.h
all: program

#Compile the main program
program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ)

run: program
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./program

#Compile each .c file into an object file
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

#Clean up compiled files
clean:
	rm -f *.o program
