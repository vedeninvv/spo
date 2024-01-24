#ifndef LAB_AST_H
#define LAB_AST_H

typedef struct ASTNode ASTNode;

struct ASTNode {
    int id;
    char* type;
    char* value;
    ASTNode* left;
    ASTNode* right;
};

ASTNode* createNode(char* type, char* value, ASTNode* left, ASTNode* right);

void printAST();

#endif //LAB_AST_H