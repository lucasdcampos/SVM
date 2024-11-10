#pragma once

#define HALT 0x00
#define IPUSH 0x01
#define IPOP  0x02
#define IADD  0x03
#define ISUB  0x04
#define IMUL  0x05
#define IDIV  0x06
#define JUMP 0x07
#define IPRINT 0x08
#define CPRINT 0x9
#define JLT 0xA
#define JLEQ 0xB
#define JGT 0xC
#define JGEQ 0xD
#define JEQ 0xE
#define JNEQ 0xF
#define JZ 0x10

#define NL IPUSH, '\n', CPRINT // Not an actual instruction, just a little cheat