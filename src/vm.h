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

void debugState(VM* vm);
void loadProgram(VM* vm, const int* program, const size_t length);
int executeProgram(VM* vm, const int stackSize);
int handle_push(VM* vm, const int value);
int handle_pop(VM* vm);
int handle_jump(VM* vm, const int address);
int handle_conditional_jmp(VM* vm, const int value, const int address);
int handle_bin_op(VM* vm);
int handle_print(VM* vm);
int handle_cprint(VM* vm);