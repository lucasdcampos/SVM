#include <stdio.h>
#include <stdlib.h>
#include "opcodes.h"
#include "vm.h"

// example program
int program[] = {
    IPUSH, 69,
    IPRINT,
    IPOP,
    JUMP, 0
};

int main(void) {
    VM vm;
    loadProgram(&vm, program, 7);
    int _1KB = 1000; // 1KB
    executeProgram(&vm, _1KB);
    return 0;
}