#include <stdio.h>
#include <stdlib.h>
#include "opcodes.h"
#include "vm.h"

// example program
int program[] = {
    IPUSH, 'H', CPRINT,
    IPUSH, 'e', CPRINT,
    IPUSH, 'l', CPRINT,
    IPUSH, 'l', CPRINT,
    IPUSH, 'o', CPRINT,
    IPUSH, ',', CPRINT,
    IPUSH, ' ', CPRINT,
    IPUSH, 'W', CPRINT,
    IPUSH, 'o', CPRINT,
    IPUSH, 'r', CPRINT,
    IPUSH, 'l', CPRINT,
    IPUSH, 'd', CPRINT,
    IPUSH, '!', CPRINT,
    IPUSH, '\n', CPRINT,
    HALT
};


int main(void) {
    VM vm;
    loadProgram(&vm, program, 43);
    int _1KB = 1000; // 1KB
    executeProgram(&vm, _1KB);
    return 0;
}