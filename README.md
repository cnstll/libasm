# libasm

# Makefile
## Create the static lib, libasm:
make all

# Compiling with test file
clang -Werror -Wextra -Wall main.c -L. -lasm
