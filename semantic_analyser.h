#ifndef LAB_3_SEMANTIC_ANALYSER_H
#define LAB_3_SEMANTIC_ANALYSER_H

#include "preprocess_ast.h"
#include "builtin_functions.h"

int processSemantics(processedFunc *funcs, int count, builtinFunctions functions);


#endif //LAB_3_SEMANTIC_ANALYSER_H
