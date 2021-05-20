#include <iostream>
#include "chunk.h"
#include "debug.h"

int main() {
    Chunk chunk;

    chunk.code.push_back(OP_RETURN);
    disassembleChunk(&chunk, "Test chunk");
    chunk.code.clear();

    return 0;
}
