#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "parser.tab.h"
#include "ast.h"
#include "cfg.h"
#include "preprocess_ast.h"
#include "semantic_analyser.h"
#include "asm_generator.h"
#include "builtin_functions.h"

#include <locale.h>
#include <sys/stat.h>
#include <string.h>

#define codeAsmOutFilename "out/out.asm.code"
#define dataAsmOutFilename "out/out.asm.data"

extern int yyparse();

extern FILE *yyin;

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

const char *DIR = "out";

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    FILE* input_file = fopen(argv[1], "r");
    if (input_file) {
        printf("work");
    }
    fclose(input_file);

    if (argc < maxCountOfNodesLists) {
        if (argc > 1) {
            for (int i = 1; i < argc; ++i) {
                FILE *input_file = fopen(argv[i], "r");
                if (input_file) {
                    allNodes[fileNum] = createNodes();
                    yyin = input_file;
                    yyparse();
                    fclose(input_file);
                    fileNum++;
                } else {
                    printf("The file could not be opened: %s\n", argv[i]);
                }
            }
            printf("findAllProcedures\n");
            ASTNodes allProcedures = findAllProcedures();
            printf("prepareProcedures\n");
            processedFunc *funcsAfterPreprocessing = prepareProcedures(allProcedures);
            printf("getBuiltinFunctions\n");
            builtinFunctions builtinFuncs = getBuiltinFunctions();
            printf("processSemantics\n");
            char* start = processSemantics(funcsAfterPreprocessing, allProcedures.count, builtinFuncs);
            if (start == NULL) {
                return 1;
            }
            FILE *code = fopen(codeAsmOutFilename, "w+");
            if (!code) {
                printf("The file could not be opened: "codeAsmOutFilename);
                return 1;
            }
            FILE *data = fopen(dataAsmOutFilename, "w+");
            if (!data) {
                fclose(code);
                printf("The file could not be opened: "dataAsmOutFilename);
                return 1;
            }
            asmCodeOut = code;
            asmDataOut = data;
            printf("generate_asm\n");
            int res = generate_asm(funcsAfterPreprocessing, allProcedures.count, builtinFuncs, start);
            fclose(code);
            fclose(data);
            if (res != 0) {
                return 1;
            }
            destroy();
        } else {
            printf("Execute: %s <input_file>\n", argv[0]);
        }
    } else {
        printf("Max input files %s", maxCountOfNodesLists);
        return 1;
    }

    return 0;
}