#ifndef LAB1_CFG_H
#define LAB1_CFG_H

#include "ast.h"

//Func
typedef struct processedFunc processedFunc;

struct processedFunc {
    char* identifier;
    ASTNode* body;
};

ASTNodes findAllFuncs();

processedFunc processFunc(ASTNode* procedure);

//CFG
typedef struct CFG CFG;
typedef struct Link Link;
typedef struct LinkList LinkList;
typedef struct Block Block;
typedef struct BlockList BlockList;
typedef struct CFGBuilder CFGBuilder;

CFG* makeCFG(processedFunc f, int nextId);
void CFG_print(FILE* f, CFG* cfg, CFG** cfgs, int countCfgs);

struct Block {
    int id;
    char* call;
    LinkList* predecessors;
    LinkList* exits;
    ASTNode* node;
    char* circleInfo;
};

Block* NewBlock(int id, char* call, ASTNode* node);

struct BlockList {
    Block** blocks;
    int count;
};

BlockList* NewBlockList();

struct CFGBuilder {
    BlockList* after_loop_block_stack;
    BlockList* curr_loop_guard_stack;
    Block* current_block;
    BlockList* calls;
    int current_id;
    CFG* cfg;
};

void CFGBuilder_visit(CFGBuilder* cfgBuilder, ASTNode* node, int dowhile);

struct CFG {
    char* procedureName;
    Block* entryblock;
    int nextId;
};

CFG* NewCFG(char* procedureName, Block* entryblock);

struct Link {
    Block* source;
    Block* target;
    char* comment;
};

Link* NewLink(Block* source, Block* target, char* string);

struct LinkList {
    Link** links;
    int count;
};

LinkList* NewLinkList();

#endif //LAB1_CFG_H