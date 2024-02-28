#ifndef LAB_3_ASM_GENERATOR_H
#define LAB_3_ASM_GENERATOR_H

#include "preprocess_ast.h"
#include "builtin_functions.h"

extern int labelCounter;
extern FILE *asmCodeOut;
extern FILE *asmDataOut;

int generate_asm(processedFunc *funcs, int count, builtinFunctions functions);

#endif //LAB_3_ASM_GENERATOR_H
