#ifndef LAB_AST_H
#define LAB_AST_H

#include <stdio.h>

#define maxCountOfNodesLists 1024

typedef struct ASTNode ASTNode;

typedef struct ASTNodes ASTNodes;

struct ASTNodes {
    ASTNode** nodes;
    int count;
};

struct ASTNode {
    int id;
    char* type;
    char* value;
    ASTNode* left;
    ASTNode* right;
    char* valueNameCur;
};

void destroy();

ASTNode* createNode(char* type, char* value, ASTNode* left, ASTNode* right);

void printAST(FILE* f);

ASTNodes* createNodes();

#endif //LAB_AST_H