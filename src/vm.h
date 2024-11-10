#pragma once
#include <stddef.h>

typedef struct
{
    int ip;
    int sp;
    int* stack;
    const int* program;
    size_t programLength;
}VM;

void loadProgram(VM* vm, const int* program, const size_t length);
int executeProgram(VM* vm, const int stackSize);
int handle_push(VM* vm, const int value);
int handle_pop(VM* vm);
int handle_jump(VM* vm, const int address);
int handle_bin_op(VM* vm);
int handle_print(VM* vm);