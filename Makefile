CC = gcc
CFLAGS = -Wall -Wextra

# List of source files
SOURCES = Driver.c Main.c PriorityQueue.c

# List of header files
HEADERS = Driver.h Node.h PriorityQueue.h

# Object files generated from source files
OBJECTS = $(SOURCES:.c=.o)

# Name of the executable
EXECUTABLE = program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

