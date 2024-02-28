#ifndef LAB_3_PREPROCESS_AST_H
#define LAB_3_PREPROCESS_AST_H

#include "ast.h"

typedef struct processedType processedType;
typedef struct expressionsList expressionsList;
typedef struct processedStatement processedStatement;
typedef struct processedBlock processedBlock;
typedef struct processedExpression processedExpression;
typedef struct processedUnary processedUnary;
typedef struct processedBinary processedBinary;
typedef struct processedCall processedCall;
typedef struct processedIndexer processedIndexer;
typedef struct processedLiteral processedLiteral;
typedef struct processedVars processedVars;
typedef struct processedVar processedVar;
typedef struct processedFunc processedFunc;
typedef struct processedAssigment processedAssigment;
typedef struct conditionalStatement conditionalStatement;
typedef struct processedIf processedIf;
typedef struct processedWhile processedWhile;
typedef struct processedDoWhile processedDoWhile;

typedef enum statementType statementType;
typedef enum expressionType expressionType;
typedef enum binaryType binaryType;
typedef enum unaryType unaryType;
typedef enum primitiveType primitiveType;
typedef enum BOOLEAN BOOLEAN;


enum primitiveType {
    CHARACTER, INT, BOOL, VOID, CUSTOM, FUNC, RESERVED
};

enum BOOLEAN {
    BOOLEAN_TRUE,
    BOOLEAN_FALSE
};

enum binaryType {
    BINARY_TYPE_PLUS,
    BINARY_TYPE_MINUS,
    BINARY_TYPE_STAR,
    BINARY_TYPE_SLASH,
    BINARY_TYPE_PERCENT,
    BINARY_TYPE_EQUAL,
    BINARY_TYPE_NOTEQUAL,
    BINARY_TYPE_LESSTHAN,
    BINARY_TYPE_GREATERTHAN,
    BINARY_TYPE_LESSTHANEQ,
    BINARY_TYPE_GREATERTHANEQ,
    BINARY_TYPE_AND,
    BINARY_TYPE_OR,
};

enum unaryType {
    UNARY_TYPE_MINUS,
    UNARY_TYPE_NOT
};

enum expressionType {
    UNARY,
    BINARY,
    BRACES,
    CALL,
    INDEXER,
    PLACE,
    LITERAL
};

enum statementType {
    STATEMENT_TYPE_BLOCK,
    STATEMENT_TYPE_VAR,
    STATEMENT_TYPE_IF,
    STATEMENT_TYPE_WHILE,
    STATEMENT_TYPE_DO_WHILE,
    STATEMENT_TYPE_BREAK,
    STATEMENT_TYPE_EXPRESSION,
    STATEMENT_TYPE_ASSIGMENT,
    STATEMENT_TYPE_RETURN,
};

const char *primitiveType_toString(primitiveType type);

struct processedType {
    primitiveType type;
    char *customTypeIdentifier;
    int arrayDem;
    ASTNode *astNode;
};

struct processedVar {
    processedType type;
    char* identifier;
    processedExpression* initValue;
    int isInitValueExists;
    ASTNode* astNode;

    // for function args
    char* label;
};

struct processedLiteral {
    processedType type;
    char c_value;
    int i_value;
    char *s_value;
    BOOLEAN b_value;
    ASTNode *astNode;
};

struct expressionsList {
    processedExpression *expressions;
    int expressionsCount;
    ASTNode *astNode;
};

struct processedCall {
    char *procedureName;
    expressionsList argumentExpressions;
    ASTNode *astNode;
};

struct processedIndexer {
    processedExpression *expression;
    expressionsList indexExpressions;
    ASTNode *astNode;
};

struct processedBinary {
    binaryType type;
    processedExpression *leftOperand;
    processedExpression *rightOperand;
    ASTNode *astNode;
};

struct processedUnary {
    unaryType type;
    processedExpression *operand;
    ASTNode *astNode;
};

struct processedExpression {
    expressionType type;

    union {
        processedUnary unary;
        processedBinary binary;
        processedExpression *expression;
        processedCall call;
        processedIndexer indexer;
        processedLiteral literal;
        char *identifier;
    };
    ASTNode *astNode;
};

struct processedBlock {
    processedStatement *statements;
    int statementsCount;
    ASTNode *astNode;
};
struct processedVars {
    processedVar *vars;
    int count;
    ASTNode *astNode;
};

struct processedWhile {
    processedExpression condition;
    processedBlock block;
    ASTNode *astNode;
};

struct processedDoWhile {
    processedExpression condition;
    processedBlock block;
    ASTNode *astNode;
};

struct processedAssigment {
    processedExpression to;
    processedExpression *rightPart;
    ASTNode *astNode;
};

struct processedStatement {
    statementType type;
    union {
        processedBlock block;
        processedExpression expression;
        processedIf *ifp;
        processedVars vars;
        processedWhile whilep;
        processedDoWhile dowhile;
        processedAssigment assigment;
    };
    ASTNode *astNode;
};

struct processedFunc {
    char *identifier;
    processedVars args;
    processedType returnType;
    processedBlock body;
    int seen;
    ASTNode *astNode;
};

struct conditionalStatement {
    processedExpression condition;
    processedStatement statement;
    ASTNode *astNode;
};

struct processedIf {
    conditionalStatement statement;
    processedStatement elseStatement;
    int elseStatementExists;
    ASTNode *astNode;
};


processedBlock prepareBlock(ASTNode *body);

processedExpression *prepareExpression(ASTNode *node);

processedStatement prepareStatement(ASTNode *node);

processedFunc prepareProcedure(ASTNode *procedure);

processedFunc *prepareProcedures(ASTNodes allProcedures);

#endif //LAB_3_PREPROCESS_AST_H
