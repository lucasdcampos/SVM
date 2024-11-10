#include <stdio.h>
#include <stdlib.h>
#include "opcodes.h"
#include "memory.h"


int handle_push(int value);
int handle_pop();
int handle_bin_op();
int handle_print();

int ip = 0;
int sp = -1;
int* stack;

int program[] = {
    IPUSH, 0x0A,
    IPUSH, 0x03,
    IADD,
    IPUSH, 0x02,
    IMUL,
    IPRINT,
    HALT
};

int main(void) {
    stack = createMemory(1000);
    int programSize = sizeof(program) / sizeof(program[0]);

    while (ip < programSize) {
        int current = program[ip];
        switch (current)
        {
        case IPUSH:
            handle_push(program[ip + 1]);
            ip++;
            break;
        case IPOP:
            handle_pop();
            break;
        case IADD:
        case ISUB:
        case IMUL:
        case IDIV:
            handle_bin_op();
            break;
        case IPRINT:
            handle_print();
            break;
        case HALT:
            return 0;
        default:
            break;
        }
        ip++;
    }

    free(stack);
    return 0;
}

int handle_push(int value) {
    sp++;
    stack[sp] = value;
    return stack[sp];
}

int handle_pop() {
    if (sp >= 0) {
        int value = stack[sp];
        sp--;
        return value;
    }
    return -1;
}

int handle_bin_op()
{
    if (sp >= 1) {
        int rhs = handle_pop();
        int lhs = handle_pop();
        switch (program[ip])
        {
            case IADD: return handle_push(lhs + rhs);
            case ISUB: return handle_push(lhs - rhs);
            case IMUL: return handle_push(lhs * rhs);
            case IDIV: return handle_push(lhs / rhs);
        }
        
    }
    return -1;
}

int handle_print() {
    if (sp >= 0) {
        printf("%d\n", stack[sp]);
    } else {
        printf("Stack is empty!\n");
    }
    ip++;
}
