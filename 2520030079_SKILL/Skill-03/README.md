# Skill-03: Shell Parsing and Process Execution

## Objective

To understand shell quoting, escape sequences, and child process execution using C programs in Ubuntu/Linux.

## Programs

### 1. Single Quotes

File: `single_quotes.c`

Demonstrates:
- Preserving literal content
- Preventing variable expansion
- Storing quoted strings
- Validating parsing results
- Testing edge cases

### 2. Double Quotes

File: `double_quotes.c`

Demonstrates:
- Preserving spaces
- Allowing variable expansion
- Handling multiple tokens
- Validating outputs
- Testing quoted content

### 3. Process Escape Sequences

File: `escape_sequences.c`

Demonstrates:
- Escaped spaces
- Escaping special symbols
- Preserving characters
- Validating parser output
- Testing complex inputs

### 4. Child Processes

File: `child_process.c`

Demonstrates:
- Creating a child process using `fork()`
- Executing a program using `execlp()`
- Passing command arguments
- Handling execution errors
- Managing parent-child processes using `wait()`

## Compilation

```bash
gcc -Wall -Wextra single_quotes.c -o single_quotes
gcc -Wall -Wextra double_quotes.c -o double_quotes
gcc -Wall -Wextra escape_sequences.c -o escape_sequences
gcc -Wall -Wextra child_process.c -o child_process
