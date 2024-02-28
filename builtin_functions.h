#ifndef LAB_3_BUILTIN_FUNCTIONS_H
#define LAB_3_BUILTIN_FUNCTIONS_H

#include "preprocess_ast.h"

typedef struct builtinFunction builtinFunction;
typedef struct builtinFunctions builtinFunctions;
#define countOfBuiltinFunctions 2

struct builtinFunction {
    processedFunc func;
    const char *asmBody;
};

struct builtinFunctions {
    builtinFunction *functions;
    int count;
};
char* strToHeap(char* s);

builtinFunctions getBuiltinFunctions();


#endif //LAB_3_BUILTIN_FUNCTIONS_H
