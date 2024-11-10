#include <stdio.h>
#include <stdlib.h>
#include "opcodes.h"
#include "vm.h"

// example program (prints the entire alphabet)
int program[] = {
    IPUSH, 65,
    CPRINT,
    IPUSH, 1,
    IADD,
    JLT, 91, 2,
    NL,
    HALT
};

int main(void) {
    VM vm;
    int _1KB = 1000; // 1KB
    loadProgram(&vm, program, 13);
    executeProgram(&vm, _1KB);
    return 0;
}