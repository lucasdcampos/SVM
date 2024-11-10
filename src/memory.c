#include "memory.h"
#include <stdlib.h>

int* createMemory(int sizeInBytes)
{
    int* memoryArray;
    memoryArray = malloc(sizeInBytes/4);
    return memoryArray;
}