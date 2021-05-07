# libasm
## Assembly ?
An assembly (or assembler) language, often abbreviated asm, is a low-level programming
language for a computer, or other programmable device, in which there is a very strong
(but often not one-to-one) correspondence between the language and the architecture’s
machine code instructions. Each assembly language is specific to a particular computer
architecture. In contrast, most high-level programming languages are generally portable
across multiple architectures but require interpreting or compiling. Assembly language
may also be called symbolic machine code.
## Presentation of the project
The project aims at building a library of functions in asm 64bits following the Intel syntax.
The functions are compiled using the assembler NASM and designed for linux.
A main coded in C calls the functions from libasm and perform some basic tests.

## Testing the project
### Create the static lib, libasm:
make all
### Compiling with tests 
clang -Werror -Wextra -Wall main.c -L. -lasm
