#include <iostream>
#include "bytecode/chunk.h"
#include "bytecode/debug.h"

int main() {
    Chunk chunk;

    int constant_idx = chunk.add_constant(1.2);
    chunk.write_chunk(OP_CONSTANT, 123);
    chunk.write_chunk(constant_idx, 123);

    chunk.write_chunk(OP_RETURN, 123);
    disassemble_chunk(&chunk, "Test chunk");
    chunk.clear();

    return 0;
}
