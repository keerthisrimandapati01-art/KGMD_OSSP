CC = gcc
CFLAGS = -Wall -Wextra -std=c11

PROGRAMS = fork_demo exec_demo process_tree shell

all: $(PROGRAMS)

fork_demo:
	$(CC) $(CFLAGS) src/fork_demo.c -o fork_demo

exec_demo:
	$(CC) $(CFLAGS) src/exec_demo.c -o exec_demo

process_tree:
	$(CC) $(CFLAGS) src/process_tree.c -o process_tree

shell:
	$(CC) $(CFLAGS) src/shell.c -o shell

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
