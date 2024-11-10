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
#define JLET 0xA

#define NL IPUSH, '\n', CPRINT