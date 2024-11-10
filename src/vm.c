#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "opcodes.h"
#include "memory.h"

void loadProgram(VM* vm, const int* program, const size_t length) {
    vm->program = program;
    vm->programLength = length;
}

int executeProgram(VM* vm, const int stackSize) {
    vm->ip = 0;
    vm->sp = -1;

    const int* program = vm->program;

    vm->stack = createMemory(stackSize);

    while (vm->ip < vm->programLength) {
        
        int current = program[vm->ip];
        switch (current)
        {
        case IPUSH:
            handle_push(vm, program[vm->ip + 1]);
            vm->ip += 2;
            continue;
        case IPOP:
            handle_pop(vm);
            vm->ip += 1;
            break;
        case IADD:
        case ISUB:
        case IMUL:
        case IDIV:
            handle_bin_op(vm);
            vm->ip += 1;
            break;
        case JUMP:
            handle_jump(vm, program[vm->ip + 1]);
            break;
        case JLET:
            handle_jlet(vm, program[vm->ip + 1], program[vm->ip + 2]);
            break;
        case IPRINT:
            handle_print(vm);
            vm->ip += 1;
            break;
        case CPRINT:
            handle_cprint(vm);
            vm->ip += 1;
            break;
        case HALT:
            free(vm->stack);
            return 0;
        default:
            printf("\nUnknown instruction: %d\n", vm->stack[vm->ip]);
            free(vm->stack);
            return 0;
        }
    }

    free(vm->stack);
    return 0; // TODO: Return proper exit code
}


int handle_push(VM* vm, const int value) {
    vm->sp++;
    vm->stack[vm->sp] = value;
    return vm->stack[vm->sp];
}

int handle_jump(VM* vm, const int address) {
    vm->ip = address;
    return vm->ip;
}

int handle_jlet(VM* vm, const int value, const int address) {
    if(vm->stack[vm->sp] < value)
    {
        vm->ip = address;
        return vm->ip;
    }
    vm->ip += 3;

    return vm->ip;
}

int handle_pop(VM* vm) {
    if (vm->sp >= 0) {
        int value = vm->stack[vm->sp];
        vm->sp--;
        return value;
    }
    return -1;
}

int handle_bin_op(VM* vm)
{
    if (vm->sp >= 1) {
        int rhs = handle_pop(vm);
        int lhs = handle_pop(vm);
        switch (vm->program[vm->ip])
        {
            case IADD: return handle_push(vm, lhs + rhs);
            case ISUB: return handle_push(vm, lhs - rhs);
            case IMUL: return handle_push(vm, lhs * rhs);
            case IDIV: return handle_push(vm, lhs / rhs);
        }
        
    }
    return -1;
}

int handle_print(VM* vm) {
    if (vm->sp >= 0) {
        printf("%d\n", vm->stack[vm->sp]);
    } else {
        printf("Stack is empty!\n");
    }
    return 0;
}

int handle_cprint(VM* vm) {
    if (vm->sp >= 0) {
        printf("%c", vm->stack[vm->sp]);
    } else {
        printf("Stack is empty!\n");
    }
    return 0;
}

void debugState(VM* vm) {
    printf("\n-----------------------\n");
    printf("IP: 0x00%d\n", vm->ip);
    printf("SP: 0x00%d\n", vm->sp);
    printf("Stack:\n");
    for (int i = 0; i < vm->sp; i++)
    {
        printf("0x00%d: %d\n", i, vm->stack[vm->sp]);
    }
    printf("-----------------------\n");
    
}