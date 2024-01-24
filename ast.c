#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "ast.h"

ASTNode** allNodes;
uint64_t allNodesCount;

ASTNode* createNode(char* type, char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = type;

    char* buff = malloc(1024 * sizeof(char));
    strcpy(buff, value);
    node->value = buff;

    node->left = left;
    node->right = right;
   
    allNodes[allNodesCount] = node;
    allNodesCount++;

    return node;
}

void printNodeValue(ASTNode* node) {
    printf("\"Type: %s, Id: %d", node->type, node->id);
    if (strlen(node->value) > 0) {
        printf(", Value: %s", node->value);
    }
    printf("\"");
}

void printNode(ASTNode* node) {
    if (node->left) {
        printNodeValue(node);
        printf(" -> ");
        printNodeValue(node->left);
        printf(";\n");
        printNode(node->left);
    }
    if (node->right) {
        printNodeValue(node);
        printf(" -> ");
        printNodeValue(node->right);
        printf(";\n"); 
        printNode(node->right);
    }
}

void printAST() {
    for (int i = 0; i < allNodesCount; i++) {
        allNodes[i]->id = i;
    }

    printf("digraph G {\n");
    printNode(allNodes[allNodesCount - 1]);

    printNodeValue(allNodes[allNodesCount - 1]);
    printf(" [shape=Mdiamond];\n");
    printf("}\n");
}