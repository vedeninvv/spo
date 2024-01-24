#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "parser.tab.h"
#include "ast.h"

extern int yyparse();
extern FILE* yyin;

extern ASTNode** allNodes;
extern uint64_t allNodesCount;

int main(int argc, char** argv) {
    allNodes = malloc(1024 * 8 * sizeof(ASTNode*));
    allNodesCount = 0;

    if (argc > 1) {
        FILE* input_file = fopen(argv[1], "r");
        if (input_file) {
            yyin = input_file;
            yyparse();
            fclose(input_file);
            printAST();
        } else {
            printf("Could not open file: %s\n", argv[1]);
        }
    } else {
        printf("Run: %s <input_file>\n", argv[0]);
    }
    return 0;
}