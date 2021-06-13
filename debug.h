#ifndef CPPLOX_DEBUG_H
#define CPPLOX_DEBUG_H

#include <string>
#include <iostream>
#include <iomanip>
#include "chunk.h"

int constant_instruction(std::string &&name, Chunk *chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    std::cout << name << " " << constant << " ";
    printValue(chunk->constants[constant]);
    std::cout << std::endl;

    return offset + 2;
}

int simple_instruction(const std::string &&name, int offset) {
    std::cout << name << std::endl;
    return offset + 1;
}

int disassemble_instruction(Chunk *chunk, int offset) {
    std::cout << std::setfill('0') << std::setw(4) << offset << " ";

    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]) {
        std::cout << "   | ";
    } else {
        std::cout << std::setfill('0') << std::setw(4) << chunk->lines[offset] << " ";
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        default:
            std::cerr << "Unknown opcode " << instruction << std::endl;
            return offset + 1;
    }
}

void disassemble_chunk(Chunk *chunk, const std::string &name) {
    std::cout << "== " << name << " ==" << std::endl;

    for (int offset = 0; offset < chunk->code.size();) {
        offset = disassemble_instruction(chunk, offset);
    }
}

#endif //CPPLOX_DEBUG_H
