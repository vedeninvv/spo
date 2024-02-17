#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cfg.h"

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

char* cloneChar(char* toClone) {
    char* buff = malloc(strlen(toClone) * sizeof(char));
    strcpy(buff, toClone);

    return buff;
}

char* concat(char* a, char* b) {
    char* c = malloc(strlen(a) + strlen(b) + 1);
    sprintf(c, "%s%s", a, b);
    return c;
}

ASTNodes findAllFuncs() {
    ASTNodes funcDefs = createNodes();
    for (int i = 0; i < fileNum; ++i) {
        for (int j = 0; j < allNodes[i].count; ++j) {
            if (strcmp(allNodes[i].nodes[j]->type, "sourceItem") == 0) {
                funcDefs.nodes[funcDefs.count] = allNodes[i].nodes[j];
                funcDefs.count++;
            }
        }
    }
    return funcDefs;
}

processedFunc processFunc(ASTNode* func) {
    processedFunc pf = {};
    if (!func && strcmp(func->type, "sourceItem") != 0 && !func->left
        && !func->right && !func->left->left && !func->left->left->right) {
        printf("Not valid func");
        return pf;
    }
    pf.identifier = func->left->left->right->value;
    pf.body = func->right;
    return pf;
}

Block* NewBlock(int id, char* call, ASTNode* node) {
    Block* block = malloc(sizeof(Block));

    block->id = id;
    block->node = node;
    block->call = cloneChar(call);
    block->predecessors = NewLinkList();
    block->exits = NewLinkList();

    return block;
}

BlockList* NewBlockList() {
    BlockList* list = malloc(sizeof(BlockList));

    list->blocks = malloc(sizeof(Block*) * 1024);
    list->count = 0;

    return list;
}

void BlockList_push(BlockList* list, Block* block) {
    list->blocks[list->count] = block;
    list->count++;
};

LinkList* NewLinkList() {
    LinkList* list = malloc(sizeof(LinkList));

    list->links = malloc(sizeof(Link*) * 1024);
    list->count = 0;

    return list;
}

void LinkList_push(LinkList* list, Link* link) {
    list->links[list->count] = link;
    list->count++;
};

Link* NewLink(Block* source, Block* target, char* comment) {
    Link* link = malloc(sizeof(Link));

    link->source = source;
    link->target = target;
    link->comment = comment;

    return link;
}

void BlockList_pop(BlockList* list) {
    list->count--;
    if (list->count < 0) {
        list->count = 0;
    }
}

void CFGBuilder_init(CFGBuilder* cfgBuilder) {
    cfgBuilder->after_loop_block_stack = NewBlockList();
    cfgBuilder->curr_loop_guard_stack = NewBlockList();
    cfgBuilder->calls = NewBlockList();
    cfgBuilder->current_block = NULL;
}

Block* CFGBuilder_newBlock(CFGBuilder* cfgBuilder, char* call, ASTNode* node) {
    cfgBuilder->current_id++;
    return NewBlock(cfgBuilder->current_id, call, node);
}

void AddExit(Block* block, Block* nextBlock, char* comment) {
    Link* link = NewLink(block, nextBlock, comment);
    LinkList_push(block->exits, link);
    LinkList_push(nextBlock->predecessors, link);
}

char* NodeFindIdent(ASTNode* node) {
    if (node == NULL ||
        strcmp(node->type, "if") == 0 ||
        strcmp(node->type, "else") == 0 ||
        strcmp(node->type, "while") == 0 ||
        strcmp(node->type, "dowhile") == 0 ||
        strcmp(node->type, "break") == 0
        ) {
        return "";
    }

    if (strcmp(node->type, "TRUE") == 0 ||
        strcmp(node->type, "FALSE") == 0 ||
        strcmp(node->type, "STR") == 0 ||
        strcmp(node->type, "CHAR") == 0 ||
        strcmp(node->type, "HEX") == 0 ||
        strcmp(node->type, "BIN") == 0 ||
        strcmp(node->type, "DEC") == 0) {
        char* result = malloc(strlen(node->value) + 5);
        sprintf(result, "%s", node->value);
        return result;
    }

    if (strcmp(node->type, "IDENTIFIER") == 0 ||
        strcmp(node->type, "INTEGER") == 0 ||
        strcmp(node->type, "LONG") == 0 ||
        strcmp(node->type, "ULONG") == 0 ||
        strcmp(node->type, "UINT") == 0
        ) {
        char* result = malloc(strlen(node->valueNameCur) + 5);
        sprintf(result, "%s", node->valueNameCur);
        return result;
    }

    if (strcmp(node->type, "listExpr") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        if (rightSide[0] != '\0') {
            char* res = concat(leftSide, ", ");
            return concat(res, rightSide);
        }
    }

    if (strcmp(node->type, "TYPEDEF") == 0) {
        return node->value;
    };

    if (strcmp(node->type, "assigment") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        if (rightSide[0] != '\0') {
            char* res = concat(leftSide, " = ");
            return concat(res, rightSide);
        }
    };

    if (strcmp(node->type, "var") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        if (rightSide[0] != '\0') {
            char* res = concat(leftSide, " ");
            return concat(res, rightSide);
        }
    }

    if (strcmp(node->type, "ASSIGN") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "=");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "PLUS") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "+");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "MINUS") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "-");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "STAR") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "*");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "DIVIDE") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "/");
        return concat(res, rightSide);
    }

    if (strcmp(node->type, "CALL") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "(");
        if (rightSide)
            res = concat(res, rightSide);
        return concat(res, ");");
    }

    if (strcmp(node->type, "block") == 0) {
        return NULL;
    }

    char* leftSide = NodeFindIdent(node->left);
    char* rightSide = NodeFindIdent(node->right);
    return concat(leftSide, rightSide);
}

char* NodeFindIdentByFirstBlock(ASTNode* node) {
    if (node != NULL) {}
    if (node == NULL) {
        return "";
    }
    if (strcmp(node->type, "if") == 0 ||
        strcmp(node->type, "else") == 0 ||
        strcmp(node->type, "while") == 0 ||
        strcmp(node->type, "dowhile") == 0 ||
        strcmp(node->type, "break") == 0
        ) {
        return "stop";
    }
    else {
        if (strcmp(node->type, "IDENTIFIER") == 0 ||
            strcmp(node->type, "INTEGER") == 0 ||
            strcmp(node->type, "LONG") == 0 ||
            strcmp(node->type, "ULONG") == 0 ||
            strcmp(node->type, "UINT") == 0
            ) {
            char* result = malloc(strlen(node->valueNameCur) + 5);
            sprintf(result, "%s", node->valueNameCur);
            return result;
        }

        if (strcmp(node->type, "listStatement") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            if (strcmp(leftSide, "stop") == 0) {
                return "";
            }
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            if (strcmp(rightSide, "stop") == 0) {
                return "";
            }
            if (leftSide[0] != '\0') {
                char* res = concat(leftSide, ";\n");
                return concat(res, rightSide);
            }
        }

        if (strcmp(node->type, "ASSIGN") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "=");
            return concat(res, rightSide);
        }
        if (strcmp(node->type, "PLUS") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "+");
            return concat(res, rightSide);
        }
        if (strcmp(node->type, "MINUS") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "-");
            return concat(res, rightSide);
        }
        if (strcmp(node->type, "STAR") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "*");
            return concat(res, rightSide);
        }
        if (strcmp(node->type, "DIVIDE") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "/");
            return concat(res, rightSide);
        }
        if (strcmp(node->type, "CALL") == 0) {
            char* leftSide = NodeFindIdentByFirstBlock(node->left);
            char* rightSide = NodeFindIdentByFirstBlock(node->right);
            char* res = concat(leftSide, "(");
            res = concat(res, rightSide);
            return concat(res, ")");
        }

        char* leftSide = NodeFindIdentByFirstBlock(node->left);
        char* rightSide = NodeFindIdentByFirstBlock(node->right);
        return concat(leftSide, rightSide);
    }
}

void CFGBuilder_visitIf(CFGBuilder* cfgBuilder, ASTNode* node) {
    Block* ifBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    ASTNode* ifBodyNode = node->left;
    ASTNode* blockIfBody = node->right->left;
    ifBlock->circleInfo = NodeFindIdent(blockIfBody);

    ASTNode* elseNode = node->right->right;

    AddExit(cfgBuilder->current_block, ifBlock, concat("IF ", ifBodyNode->value));

    Block* afterIfBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    if (elseNode != NULL) {
        Block* elseBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL);
        AddExit(cfgBuilder->current_block, elseBlock, "ELSE");
        cfgBuilder->current_block = elseBlock;
        cfgBuilder->current_block->circleInfo = NodeFindIdentByFirstBlock(elseNode->left->left);
        CFGBuilder_visit(cfgBuilder, elseNode, 0);

        if (cfgBuilder->current_block->exits->count == 0) {
            AddExit(cfgBuilder->current_block, afterIfBlock, "");
        }
    }
    else {
        AddExit(cfgBuilder->current_block, afterIfBlock, "");
    }

    cfgBuilder->current_block = ifBlock;

    ASTNode* nextBlock = node->right->left;
    CFGBuilder_visit(cfgBuilder, nextBlock, 0);

    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, afterIfBlock, "");
    }

    cfgBuilder->current_block = afterIfBlock;
}

Block* CFGBuilder_newLoopGuard(CFGBuilder* cfgBuilder) {
    if (cfgBuilder->current_block->exits->count == 0) {
        return cfgBuilder->current_block;
    }

    Block* loopguard = CFGBuilder_newBlock(cfgBuilder, "", NULL);

    AddExit(cfgBuilder->current_block, loopguard, "loop");

    return loopguard;
}

void CFGBuilder_visitDoWhile(CFGBuilder* cfgBuilder, ASTNode* node) {
    Block* loopguard = CFGBuilder_newLoopGuard(cfgBuilder);
    ASTNode* doWhileBodyNode = node->right;
    cfgBuilder->current_block = loopguard;
    BlockList_push(cfgBuilder->curr_loop_guard_stack, loopguard);

    Block* whileBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    AddExit(loopguard, whileBlock, "do");
    cfgBuilder->current_block = whileBlock;
    Block* afterWhile = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);

    CFGBuilder_visit(cfgBuilder, node->left, 1);

cfgBuilder->current_block->circleInfo = NodeFindIdent(node->left);
AddExit(cfgBuilder->current_block, loopguard, concat("while ", doWhileBodyNode->value));
AddExit(cfgBuilder->current_block, afterWhile, "");
cfgBuilder->current_block = afterWhile;

BlockList_pop(cfgBuilder->after_loop_block_stack);
BlockList_pop(cfgBuilder->curr_loop_guard_stack);
}

void CFGBuilder_visitWhile(CFGBuilder* cfgBuilder, ASTNode* node) {
    Block* loopguard = CFGBuilder_newLoopGuard(cfgBuilder);
    ASTNode* whileBodyNode = node->left;

    cfgBuilder->current_block = loopguard;
    BlockList_push(cfgBuilder->curr_loop_guard_stack, loopguard);

    Block* whileBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    AddExit(cfgBuilder->current_block, whileBlock, concat("while ", whileBodyNode->value));

    Block* afterWhile = CFGBuilder_newBlock(cfgBuilder, "", NULL);
    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);
    AddExit(cfgBuilder->current_block, afterWhile, "");

    cfgBuilder->current_block = whileBlock;
    cfgBuilder->current_block->circleInfo = NodeFindIdent(node->right);
    CFGBuilder_visit(cfgBuilder, node->right, 0);

    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, loopguard, "");
    }

    cfgBuilder->current_block = afterWhile;
    //cfgBuilder->current_block->circleInfo = NodeFindIdent(node);
    BlockList_pop(cfgBuilder->after_loop_block_stack);
    BlockList_pop(cfgBuilder->curr_loop_guard_stack);
}

void CFGBuilder_visitCall(CFGBuilder* cfgBuilder, ASTNode* node) {
    char* callName = NodeFindIdent(node);
    Block* callF = CFGBuilder_newBlock(cfgBuilder, callName, NULL);
    AddExit(callF, callF, "CloseCall");

    ASTNode* nextBlock = node->right->left;

    if (!strstr(node->value, "var")) {
        CFGBuilder_visit(cfgBuilder, nextBlock, 0);
    }
    Block* afterCallBlock = CFGBuilder_newBlock(cfgBuilder, "AfterCall", NULL);
    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, afterCallBlock, "");
    }
    cfgBuilder->current_block = afterCallBlock;
}

void CFGBuilder_visitCallEnd(CFGBuilder* cfgBuilder, ASTNode* node) {
    char* callName = NodeFindIdent(node);
    Block* callF = CFGBuilder_newBlock(cfgBuilder, callName, NULL);
    AddExit(callF, callF, "CloseCall");
}

void CFGBuilder_visitBreak(CFGBuilder* cfgBuilder, ASTNode* node) {
    if (cfgBuilder->after_loop_block_stack->count == 0) {
        return;
    }
    AddExit(cfgBuilder->current_block,
        cfgBuilder->after_loop_block_stack->blocks[cfgBuilder->after_loop_block_stack->count - 1], "break");
}

void next(CFGBuilder* cfgBuilder, ASTNode* node, int dowhile) {
    if (node->left) {
        if (node->right != NULL) {}
        CFGBuilder_visit(cfgBuilder, node->left, dowhile);
    }
    if (node->right) {
        if (node->left != NULL) {}
        CFGBuilder_visit(cfgBuilder, node->right, dowhile);
    }
}

void CFGBuilder_visitDoWhileEnd(CFGBuilder* cfgBuilder, ASTNode* node) {
    if (!node) {
        return;
    }

    if (strcmp(node->type, "if") == 0) {
        CFGBuilder_visitIf(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "while") == 0) {
        CFGBuilder_visitWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "dowhile") == 0) {
        CFGBuilder_visitDoWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "break") == 0) {
        CFGBuilder_visitBreak(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "CALL") == 0 || strcmp(node->type, "var") == 0 || strcmp(node->type, "assigment") == 0) {
        if (cfgBuilder->current_block->circleInfo == NULL) {
            cfgBuilder->current_block->circleInfo = NodeFindIdent(node);
        }
        CFGBuilder_visitCall(cfgBuilder, node);
        return;
    }
}

void CFGBuilder_visitEnd(CFGBuilder* cfgBuilder, ASTNode* node) {
    if (!node) {
        return;
    }

    if (strcmp(node->type, "if") == 0) {
        CFGBuilder_visitIf(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "while") == 0) {
        CFGBuilder_visitWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "dowhile") == 0) {
        CFGBuilder_visitDoWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "break") == 0) {
        CFGBuilder_visitBreak(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "CALL") == 0 || strcmp(node->type, "var") == 0 || strcmp(node->type, "assigment") == 0) {
        if (cfgBuilder->current_block->circleInfo == NULL) {
            cfgBuilder->current_block->circleInfo = NodeFindIdent(node);
        }
        CFGBuilder_visitCall(cfgBuilder, node);
        return;
    }
}

void CFGBuilder_visit(CFGBuilder* cfgBuilder, ASTNode* node, int dowhile) {
    if (!node) {
        return;
    }
    if (strcmp(node->type, "if") == 0) {
        CFGBuilder_visitIf(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "while") == 0) {
        CFGBuilder_visitWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "dowhile") == 0) {
        CFGBuilder_visitDoWhile(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "break") == 0) {
        CFGBuilder_visitBreak(cfgBuilder, node);
        return;
    }
    else if (strcmp(node-> type, "CALL") == 0 || strcmp(node->type, "var") == 0 || strcmp(node->type, "assigment") == 0) {
        if (cfgBuilder->current_block->circleInfo == NULL) {
            cfgBuilder->current_block->circleInfo = NodeFindIdent(node);
        }
        CFGBuilder_visitCall(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "listStatement") == 0) {
        int i = 0;
        for (ASTNode* stmt = node; stmt != NULL; stmt = stmt->right) {
            if (stmt->right) {
                CFGBuilder_visit(cfgBuilder, stmt->left, dowhile); // Рекурсивный вызов для левого элемента списка
            } else {
                if (dowhile == 1) {
                    CFGBuilder_visitDoWhileEnd(cfgBuilder, stmt->left);
                }
                else
                    CFGBuilder_visitEnd(cfgBuilder, stmt->left);
            }
        }
    } else {
        next(cfgBuilder, node, dowhile);
    }
}

CFG* CFGBuilder_build(CFGBuilder* cfgBuilder, char* procedureName, ASTNode* node, int nextId) {
    cfgBuilder->current_id = nextId;
    cfgBuilder->current_block = CFGBuilder_newBlock(cfgBuilder, "", node);
    cfgBuilder->cfg = NewCFG(procedureName, cfgBuilder->current_block);

    CFGBuilder_visit(cfgBuilder, node, 0);

    cfgBuilder->cfg->nextId = cfgBuilder->current_id;

    return cfgBuilder->cfg;
}

CFG* NewCFG(char* procedureName, Block* entryblock) {
    CFG* cfg = malloc(sizeof(CFG));
    cfg->procedureName = procedureName;
    cfg->entryblock = entryblock;
    return cfg;
}

void Block_print(Block* block, FILE* f) {
    if (block->circleInfo != NULL) {
        fprintf(f, "\"%d. %s\"", block->id, block->circleInfo);
    }
    else {
        fprintf(f, "\"%d\"", block->id);
    }
}

void Link_print(Link* link, FILE* f) {
    Block_print(link->source, f);
    fprintf(f, " -> ");
    Block_print(link->target, f);
    fprintf(f, "[label=\"%s\"];\n", link->comment);
}

int seenOrNot(int id, int count, int* seen) {
    for (int i = 0; i < count; ++i) {
        if (seen[i] == id) {
            return 1;
        }
    }
    return 0;
}

CFG* CFG_find(CFG** cfgs, int countCfgs, char* procedureName) {
    for (int i = 0; i < countCfgs; ++i) {
        if (strcmp(cfgs[i]->procedureName, procedureName) == 0) {
            return cfgs[i];
        }
    }
    return NULL;
}

Block* BlockFindLast(Block* block) {
    if (block->exits->count == 0) {
        return block;
    }
    return BlockFindLast(block->exits->links[0]->target);
}

void recPrint(FILE* f, Block* block, int* seen, int* count, CFG** cfgs, int countCfgs) {
    if (seenOrNot(block->id, *count, seen) != 0) {
        return;
    }
    seen[*count] = block->id;
    (*count)++;
    for (int i = 0; i < block->exits->count; ++i) {
        Link_print(block->exits->links[i], f);
        recPrint(f, block->exits->links[i]->target, seen, count, cfgs, countCfgs);
    }
    if (block->exits->count == 0) {
        Block_print(block, f);
        fprintf(f, " -> end;\n");
    }
}

void CFG_print(FILE* f, CFG* cfg, CFG** cfgs, int countCfgs) {
    int seen[1024];
    int count = 0;
    fprintf(f, "label=%s;\n", cfg->procedureName);
    recPrint(f, cfg->entryblock, seen, &count, cfgs, countCfgs);
    fprintf(f, "\nstart -> ");
    Block_print(cfg->entryblock, f);
    fprintf(f, ";\n");
}

CFG* makeCFG(processedFunc pf, int nextId) {
    CFGBuilder cfgBuilder = {};
    CFGBuilder_init(&cfgBuilder);

    CFG* cfg = CFGBuilder_build(&cfgBuilder, pf.identifier, pf.body, nextId);

    return cfg;
}