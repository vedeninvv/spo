#ifndef LAB_3_SYMBOLIC_TABLE_H
#define LAB_3_SYMBOLIC_TABLE_H

#include "preprocess_ast.h"

typedef struct symbolicTable symbolicTable;
typedef struct symbol symbol;


union ctx {
    processedFunc *func;
};

enum symbolCategory {
    SYMBOL_CATEGORY_FUNC,
    SYMBOL_CATEGORY_VAR
};

struct symbol {
    char *identifier;
    processedType type;
    enum symbolCategory category;
    union ctx ctx;
    char *label;
};

struct symbolicTable {
    symbolicTable *parent;
    symbol *symbols;
    int symbolsCount;
    char *currentFuncId;
    int capacity;
};

char *symbolicTable_currentFuncId(symbolicTable *table);

int symbolicTable_putSymbol(symbolicTable *table, processedType type, char *identifier, char* label, union ctx ctx, enum symbolCategory category);

symbol *symbolicTable_findSymbol(symbolicTable *table, char *identifier);

void symbolicTable_free(symbolicTable *table);

symbolicTable *newSymbolicTable(symbolicTable *parent);


#endif //LAB_3_SYMBOLIC_TABLE_H
