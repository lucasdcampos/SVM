#include <stdio.h>
#include "memory.h"

int handle_push(int value, int offset);
int handle_pop();
int handle_add();
int handle_print();

int ip = 0;                 // Instruction Pointer (Program Counter)
int sp = -1;                // Stack Pointer
int* stack;

// Assembly Instructions
int program[] = {
    0x01, 0x0A,             // IPUSH 0x0A (10)
    0x01, 0x03,             // IPUSH 0x03 (3)
    0x03,                   // IADD  (Adds 0x0A and 0x03)
    0xFF                    // PRINT (Should print 13)
};

int main(void) {
    
    stack = createMemory(1000);
    int current = program[ip];
    int programSize = sizeof(program) / sizeof(program[0]);

    while(current != 0x00 || ip < programSize) {
        ip++;
        switch (current)
        {
        case 0x01:
            handle_push(program[ip], 1);
            break;
        case 0x02:
            handle_pop();
            break;
        case 0x03:
            handle_add();
            break;
        case 0xFF:
            handle_print();
            break;
        default:
            break;
        }
        current = program[ip];
    }

    return 0;
}

int handle_push(int value, int offset) {
    sp++;                           // SP starts at -1
    stack[sp] = value;              // Push operand to Stack
    ip+= offset;                    // Move to Next Instruction (?)s

    return stack[sp];               // Returns the pushed value
}

int handle_pop() {
    int value = stack[sp];          // Save current value
    sp--;                           // Pops the value from the Stack
    return value;                   // Returns the popped value
}

int handle_add() {
    int rhs = handle_pop();
    int lhs = handle_pop();
    return handle_push(lhs + rhs, 0);
}

int handle_print() {
    ip++;
    printf("%d\n", stack[sp]);
}