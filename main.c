#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
#include "cfg.h"

extern ASTNodes* allNodes[maxCountOfNodesLists];
extern int fileNum;

extern int yyparse();
extern FILE* yyin;

int main(int argc, char** argv) {
    if (argc > maxCountOfNodesLists) {
        printf("Max count of input files - 1024");
        return 1;
    }

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            FILE* input_file = fopen(argv[i], "r");
            if (input_file) {
                allNodes[fileNum] = createNodes();
                yyin = input_file;
                yyparse();
                fclose(input_file);
                fileNum++;
            } else {
                printf("Can not open file: %s\n", argv[i]);
            }
        }
        
        printf("Printing AST");
        FILE* f = fopen("ast.dot", "w+");
        printAST(f);
        fclose(f);

        ASTNodes* allProcedures = findAllFuncs();
        CFG** cfgs = malloc(allProcedures->count * sizeof(CFG*));
        for (int i = 0; i < allProcedures->count; ++i) {
            ProcessedFunc* func = processFunc(allProcedures->nodes[i]);
            CFG* cfg = makeCFG(func, i);
            cfgs[i] = cfg;
        }

        for (int i = 0; i < allProcedures->count; ++i) {
            char* filename = malloc(strlen(cfgs[i]->procedureName) + 5);
            sprintf(filename, "%s.ext", cfgs[i]->procedureName);
            FILE* f = fopen(filename, "w+");
            fprintf(f, "digraph G {");
            CFG_print(f, cfgs[i], cfgs, allProcedures->count);
            fprintf(f, "start [shape=Mdiamond]; end [shape=Msquare];\n}\n");
            fclose(f);
        }

        FILE* callGraphFile = fopen("callGraph.dot", "w+");
        printCallGraph(callGraphFile, cfgs, allProcedures->count);
        fclose(callGraphFile);

        destroy();
    } else {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    return 0;
}