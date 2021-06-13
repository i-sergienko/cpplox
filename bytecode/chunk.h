#ifndef CPPLOX_CHUNK_H
#define CPPLOX_CHUNK_H

#include <vector>
#include "value.h"

enum OpCode {
    OP_CONSTANT,
    OP_RETURN
};

struct Chunk {
    std::vector<uint8_t> code;
    std::vector<Value> constants;
    std::vector<int> lines;

    void write_chunk(uint8_t byte, int line);

    int add_constant(Value value);

    void clear();
};

void Chunk::write_chunk(uint8_t byte, int line) {
    this->code.push_back(byte);
    this->lines.push_back(line);
}

int Chunk::add_constant(Value value) {
    this->constants.push_back(value);
    return this->constants.size() - 1;
}

void Chunk::clear() {
    this->code.clear();
    this->constants.clear();
    this->lines.clear();
}


#endif //CPPLOX_CHUNK_H
