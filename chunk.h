#ifndef CPPLOX_CHUNK_H
#define CPPLOX_CHUNK_H

#include <vector>

enum OpCode {
    OP_RETURN
};

struct Chunk {
    std::vector<uint8_t> code;
};

#endif //CPPLOX_CHUNK_H
