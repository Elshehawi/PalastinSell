# PalestineSell

A minimal custom shell implementation written in C for educational and learning purposes.

## 🌟 Project Overview

PalestineSell is a basic Unix-style command-line shell built to teach core operating system and systems programming concepts, including:
- Parsing user input and tokenizing commands  
- Handling built-in commands (`cd`, `pwd`, `echo`, `env`, `setenv`, `unsetenv`, `which`, `exit`)  
- Launching external programs via `fork()` + `exec()` and managing their lifecycle  
- Using `waitpid()` to wait for child processes and avoid zombies  
- Managing a dynamic environment variable array  
- Searching the `PATH` for executables  
- Basic error handling and memory management  

## 🛠️ Features

- Internal built-in commands:  
  - `cd [path]`, `cd -`, `cd ~`, `cd ..`  
  - `pwd`  
  - `echo [-n] [args]`, handling `$VARIABLE`  
  - `env`  
  - `setenv VAR [value]`  
  - `unsetenv VAR`  
  - `which COMMAND`  
  - `exit`  
- External command execution: Any command found in `PATH` can be launched, with proper forking and waiting.  
- Environment variable management: Maintains its own copy of the `env` array, supports duplication, addition, removal.  
- Safe memory handling: Uses dynamic allocation for strings, arrays, free on exit, and avoids common pitfalls.  
- Tokenizer and basic parsing logic to split user input.

## 🧑‍💻 Getting Started

### Prerequisites
- A Unix-like environment (Linux or macOS) supporting POSIX functions (`fork`, `exec`, `waitpid`).
- A recent C compiler (e.g., `gcc`) and basic build tools.

### Building
```bash
git clone https://github.com/Elshehawi/PalestineSell.git
cd PalastinSell
gcc -Wall -Wextra -Werror -g -o shell palestine_shell.c parser.c builtins.c utils.c
