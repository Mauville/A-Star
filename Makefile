CC = gcc
CFLAGS = -Wall -Wextra

# List of source files
SOURCES = Driver.c Main.c AStar.c PriorityQueue.c

# List of header files
HEADERS = Driver.h Node.h PriorityQueue.h

# Object files generated from source files
OBJECTS = $(SOURCES:.c=.o)

# Name of the main executable
EXECUTABLE = program

# List of test source files
TEST_SOURCES = PriorityQueue.c PriorityQueueTests.c

# Object files generated from test source files
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

# Name of the test executable
TEST_EXECUTABLE = test_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

tests: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)
