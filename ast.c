#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "ast.h"

ASTNodes allNodes[maxCountOfNodesLists];
int fileNum;

void destroy() {
    for (int i = 0; i < fileNum; ++i) {
        for (int j = 0; j < allNodes[i].count; ++j) {
            free(allNodes[i].nodes[j]);
        }
        free(allNodes[i].nodes);
    }
}

ASTNodes createNodes() {
    ASTNodes nodes;
    nodes.nodes = malloc(1024 * 8 * sizeof(ASTNode*));
    nodes.count = 0;
    return nodes;
}

char* ASTNode_toString(ASTNode* node) {
    if (node == NULL) {
        return "NULL";
    }
    if (node->value == NULL || strlen(node->value) == 0) {
        char* leftSide = ASTNode_toString(node->left);
        char* rightSide = ASTNode_toString(node->right);
        char* result = malloc(strlen(node->type) + strlen(leftSide) + strlen(rightSide) + 5);
        sprintf(result, "%s(%s, %s)", node->type, leftSide, rightSide);
        return result;
    }
    return node->value;
}

ASTNode* createNode(char* type, char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = type;
    node->left = left;
    node->right = right;

    char* buff;
    if (value == NULL || strlen(value) == 0) {
        buff = ASTNode_toString(node);
    }
    else {
        buff = malloc(strlen(value) + 1);
        strcpy(buff, value);
    }
    node->value = buff;
   
    allNodes[fileNum].nodes[allNodes[fileNum].count] = node;
    allNodes[fileNum].count++;

    return node;
}

void printNodeValue(FILE* f, ASTNode* node) {
    fprintf(f, "\"Type: %s, Id: %d", node->type, node->id);
    //if (strlen(node->value) > 0) {
    //    fprintf(f, ", Value: %s", node->value);
    //}
    fprintf(f, "\"");
}

void printNode(FILE* f, ASTNode* node) {
    if (node->left) {
        printNodeValue(f, node);
        fprintf(f, " -> ");
        printNodeValue(f, node->left);
        fprintf(f, ";\n");
        printNode(f, node->left);
    }
    if (node->right) {
        printNodeValue(f, node);
        fprintf(f, " -> ");
        printNodeValue(f, node->right);
        fprintf(f, ";\n"); 
        printNode(f, node->right);
    }
}

void printAST() {
    FILE* f = fopen("ast.dot", "w+");
    fprintf(f, "digraph G {\n");

    int idCounter = 0;

    for (int file = 0; file < fileNum; ++file) {
        for (int i = 0; i < allNodes[file].count; ++i) {
            allNodes[file].nodes[i]->id = idCounter;
            idCounter++;
        }
        fprintf(f, "\"ROOT\"");
        fprintf(f, " -> ");
        printNodeValue(f, allNodes[file].nodes[allNodes[file].count - 1]);
        printf(";\n");
        printNode(f, allNodes[file].nodes[allNodes[file].count - 1]);
    }

    fprintf(f, "\n}\n");

    fclose(f);
}