#include <stdio.h>
#include <string.h>


#include "memory.h"
#include "object.h"
#include "value.h"
#include "vm.h"

//@NOTE: // we need to terminate the string ourselves since the pointer points directly to the lexeme in the source.
ObjString* copyString(const char* chars, int length) {
    char* heapChars = ALLOCATE(char, length + 1); 
    memcpy(heapChars, chars, length);
    heapChars[length] = '\0';
    return allocateString(heapChars, length);
}