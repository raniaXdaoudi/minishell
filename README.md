# minishell

A simple shell implementation inspired by bash. This project is part of the 42 school curriculum and is completed as a team project.

## Description

This project involves creating a shell program that mimics basic bash functionality. It handles command execution, environment variables, redirections, pipes, and built-in commands. The project teaches about processes, file descriptors, signal handling, and command parsing in Unix-like systems.

## Features

The program implements:
- Command prompt display with working history
- Command execution with absolute and relative paths
- Built-in commands (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Environment variable handling (`$` followed by characters)
- Signal handling (ctrl-C, ctrl-D, ctrl-\\)
- Redirections (`<`, `>`, `>>`, `<<`)
- Pipes (`|`)
- Exit status handling (`$?`)
- Quote handling (single and double quotes)
- Error handling and appropriate error messages

## Getting Started

### Prerequisites
- GCC compiler
- Make
- Readline library
- Unix-based operating system (Linux/Mac)

### Installation
```bash
git clone https://github.com/yourusername/minishell.git
cd minishell
make
```

### Usage
```bash
./minishell
```

Example commands:
```bash
minishell$ ls -la
minishell$ echo "Hello World"
minishell$ cd ..
minishell$ cat file.txt | grep "pattern" > output.txt
```

## Implementation Details

The program:
1. Displays a prompt waiting for user input
2. Parses the command line (handles quotes, variables, etc.)
3. Handles redirections and pipes
4. Executes commands using execve or built-in functions
5. Manages environment variables
6. Handles signals appropriately
7. Maintains command history

## Error Handling
The program handles various error cases:
- Command not found
- Permission denied
- Invalid syntax
- Memory allocation failures
- File access errors
- Pipe and fork failures
- Signal interruptions

## Building
The project includes a Makefile with the following rules:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Rebuilds the program

## Return Value
- Returns the last command's exit status
- Displays appropriate error messages to stderr
- Properly frees all allocated memory

## Authors
- Rania (radaoudi)
- Tamsi (tbesson)

## License
This project is part of the 42 school curriculum. Please refer to 42's policies regarding code usage and distribution.

## Acknowledgments
- 42 school for providing the project requirements and framework
- Bash shell documentation and specifications
