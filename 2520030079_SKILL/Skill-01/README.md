# Skill-01: Linux Process Management

## Objective

To install and configure the Linux development environment, configure GCC and Git, create a project structure, understand shell architecture, build programs using Makefile, and analyze Linux process management using fork(), exec(), process trees, and system call tracing.

## Requirements Covered

- Linux VM / Ubuntu environment
- GCC compiler configuration
- Git repository setup
- Project structure creation
- Shell architecture
- Makefile
- Process abstraction
- fork() system call
- exec() family
- Parent-child process relationship
- Process tree
- System call tracing using strace

## Project Structure

```text
Skill-01/
├── Makefile
├── README.md
└── src/
    ├── fork_demo.c
    ├── exec_demo.c
    └── process_tree.c# Skill-01: Linux Process Management and Interactive Shell

## Objective

To understand Linux process management and develop a basic interactive shell. The skill covers process creation, process replacement, parent-child relationships, process tree inspection, system call tracing, interactive shell control flow, keyboard input handling, Backspace, Enter, input buffering, and multi-character commands.

---

# Question 1: Linux Process Management

## Requirements

- Install and configure Linux environment
- Configure GCC
- Setup Git repository
- Create project structure
- Understand shell architecture
- Build initial Makefile
- Analyze process abstraction
- Execute `fork()`
- Understand `exec()` family
- Analyze parent-child relationships
- Inspect process tree
- Practice system call tracing

## 1. Process Abstraction

A process is a program in execution.

Important process information includes:

- Process ID (PID)
- Parent Process ID (PPID)
- Process state
- Memory information
- System resources

Processes can be inspected using:

```bash
ps
ps -ef

