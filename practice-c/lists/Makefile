CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = mylist.o 
DEPS = mylist.h
all: program

#Compile the main program
program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ)

#Compile each .c file into an object file
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

#Clean up compiled files
clean:
	rm -f *.o program
