#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {

    initVM();
    Chunk chunk;
    initChunk(&chunk);

    // -( (1.2 + 3.4) / 5.6))
    // this adds a constant to the constants array,
    // writes the CONSTANT op in the bytecode array, as well as the index it has in the constants array.
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant,  123);

    constant = addConstant(&chunk, 3.4);    
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant,  123);

    writeChunk(&chunk, OP_ADD, 123);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);
    writeChunk(&chunk, OP_NEGATE, 123);
    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

    return 0;    
}