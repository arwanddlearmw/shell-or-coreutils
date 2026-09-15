# Shell & Coreutils

A small project where I'm learning C by working with Unix system calls and libraries.

The project contains simple implementations of Unix-like commands and a small shell. It's mainly for learning, experimenting, and understanding how things work under the hood.

# What is the idea?

Honestly, the main idea is simple:

I'm learning C, Unix system calls, processes, file descriptors, pipes, redirection, and other low-level concepts by building things myself.

Instead of only reading about how Unix commands work, I'm trying to implement some of them and learn from the process.

Why this project?

This is a learning project, not a replacement for the real Unix/GNU tools.

I'm building it to understand concepts such as:

C programming
Unix system calls
Processes and fork()
Program execution with exec()
File descriptors
Input/output redirection
Pipes
Basic shell behavior
Working with files and directories

If you're interested in how these things work internally, feel free to explore the code.

# Requirements

You need:

A Unix-like operating system
+ GCC or Clang
+ Make

Native Windows is not supported.

However, you can run the project on Windows using:

WSL
MSYS2
# Download

Clone the repository:
```bash
git clone https://github.com/arwanddlearmw/shell-or-coreutils.git
```

Then enter the project directory:
```bash
cd shell-or-coreutils/coreutils
```

Build the project:
```bash
make
```

After building, you should get the executable.

Using GCC

If you want to build with GCC instead of the default compiler:
```bash
make CC=gcc
```
License

This project is licensed under the GNU General Public License v2.0 (GPL-2.0).

See the LICENSE file for the full license text.
