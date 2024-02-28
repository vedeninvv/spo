#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cfg.h"

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

ASTNodes findAllProcedures() {
    ASTNodes funcDefs = createNodes();
    for (int i = 0; i < fileNum; ++i) {
        for (int j = 0; j < allNodes[i].count; ++j) {
            if (strcmp(allNodes[i].nodes[j]->type, sourceItem) == 0) {
                funcDefs.nodes[funcDefs.count] = allNodes[i].nodes[j];
                funcDefs.count++;
            }
        }
    }
    return funcDefs;
}

char* cloneChar(char* toClone) {
    char* buff = malloc(strlen(toClone) * sizeof(char) + 1);
    strcpy(buff, toClone);

    return buff;
}

char* concat(char* a, char* b) {
    char* c = malloc(strlen(a) + strlen(b) + 1);
    sprintf(c, "%s%s", a, b);
    return c;
}

ProcessedFunc* processFunc(ASTNode* func) {
    ProcessedFunc* pf = malloc(sizeof(ProcessedFunc));
    if (!func && strcmp(func->type, "sourceItem") != 0 && !func->left
        && !func->right && !func->left->left && !func->left->left->right) {
        printf("Not valid func");
        return pf;
    }
    pf->identifier = func->left->left->right->value;
    pf->body = func->right;
    return pf;
}

Block* NewBlock(int id, char* call, ASTNode* node, char* blockInfo) {
    Block* block = malloc(sizeof(Block));

    block->id = id;
    block->node = node;
    block->call = cloneChar(call);
    block->predecessors = NewLinkList();
    block->exits = NewLinkList();
    if (blockInfo != NULL && strlen(blockInfo) > 0) {
        block->info = blockInfo;
    }

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
    cfgBuilder->current_block = NULL;
}

Block* CFGBuilder_newBlock(CFGBuilder* cfgBuilder, char* call, ASTNode* node, char* blockInfo) {
    cfgBuilder->current_id++;
    return NewBlock(cfgBuilder->current_id, call, node, blockInfo);
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
        return cloneChar(node->value);
    }

    if (strcmp(node->type, "IDENTIFIER") == 0 ||
        strcmp(node->type, "INTEGER") == 0 ||
        strcmp(node->type, "LONG") == 0 ||
        strcmp(node->type, "ULONG") == 0 ||
        strcmp(node->type, "UINT") == 0) {
        return cloneChar(node->value);
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
        return cloneChar(node->value);
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
    if (strcmp(node->type, "array") == 0) {
        return concat(node->left->value, node->value);
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
    if (strcmp(node->type, "SLASH") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "/");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "LESSTHANEQ") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "<=");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "GREATERTHANEQ") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, ">=");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "LESSTHAN") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "<");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "GREATERTHAN") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, ">");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "NOTEQUAL") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "!=");
        return concat(res, rightSide);
    }
    if (strcmp(node->type, "EQUALITY") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "==");
        return concat(res, rightSide);
    }

    if (strcmp(node->type, "CALL") == 0) {
        char* leftSide = NodeFindIdent(node->left);
        char* rightSide = NodeFindIdent(node->right);
        char* res = concat(leftSide, "(");
        if (rightSide)
            res = concat(res, rightSide);
        return concat(res, ")");
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
            return cloneChar(node->valueNameCur);
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
    cfgBuilder->current_block->info = concat("IF ", NodeFindIdent(node->left));
    Block* ifBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    ASTNode* blockIfBody = node->right->left;
    ifBlock->info = NodeFindIdent(blockIfBody);

    ASTNode* elseNode = node->right->right;

    AddExit(cfgBuilder->current_block, ifBlock, "");

    Block* afterIfBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    if (elseNode != NULL) {
        Block* elseBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
        AddExit(cfgBuilder->current_block, elseBlock, "ELSE");
        cfgBuilder->current_block = elseBlock;
        cfgBuilder->current_block->info = NodeFindIdentByFirstBlock(elseNode->left->left);
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

    Block* loopguard = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");

    AddExit(cfgBuilder->current_block, loopguard, "loop");

    return loopguard;
}

void CFGBuilder_visitDoWhile(CFGBuilder* cfgBuilder, ASTNode* node) {
    Block* loopguard = CFGBuilder_newLoopGuard(cfgBuilder);
    ASTNode* doWhileBodyNode = node->right;
    cfgBuilder->current_block = loopguard;
    BlockList_push(cfgBuilder->curr_loop_guard_stack, loopguard);

    Block* whileBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    AddExit(loopguard, whileBlock, "do");
    cfgBuilder->current_block = whileBlock;
    Block* afterWhile = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);

    CFGBuilder_visit(cfgBuilder, node->left, 1);

    cfgBuilder->current_block->info = concat("while ", NodeFindIdent(doWhileBodyNode));
    AddExit(cfgBuilder->current_block, loopguard, "");
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

    Block* whileBlock = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    cfgBuilder->current_block->info = concat("while ", NodeFindIdent(whileBodyNode));
    AddExit(cfgBuilder->current_block, whileBlock, "");

    Block* afterWhile = CFGBuilder_newBlock(cfgBuilder, "", NULL, "");
    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);
    AddExit(cfgBuilder->current_block, afterWhile, "");

    cfgBuilder->current_block = whileBlock;
    cfgBuilder->current_block->info = NodeFindIdent(node->right);
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
    if (strcmp(node->type, "CALL") == 0) {
        addNewCFGLink(cfgBuilder->cfg, node->left->value);
    }
    Block* callF = CFGBuilder_newBlock(cfgBuilder, callName, NULL, "");
    AddExit(callF, callF, "CloseCall");

    ASTNode* nextBlock = node->right->left;

    if (!strstr(node->value, "var")) {
        CFGBuilder_visit(cfgBuilder, nextBlock, 0);
    }
    Block* afterCallBlock = CFGBuilder_newBlock(cfgBuilder, "AfterCall", NULL, "");
    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, afterCallBlock, "");
    }
    cfgBuilder->current_block = afterCallBlock;
}

void CFGBuilder_visitCallEnd(CFGBuilder* cfgBuilder, ASTNode* node) {
    char* callName = NodeFindIdent(node);
    Block* callF = CFGBuilder_newBlock(cfgBuilder, callName, NULL, "");
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
        if (cfgBuilder->current_block->info == NULL) {
            cfgBuilder->current_block->info = NodeFindIdent(node);
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
        if (cfgBuilder->current_block->info == NULL) {
            cfgBuilder->current_block->info = NodeFindIdent(node);
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
    else if (strcmp(node->type, "CALL") == 0 || strcmp(node->type, "var") == 0 || strcmp(node->type, "assigment") == 0) {
        if (cfgBuilder->current_block->info == NULL) {
            cfgBuilder->current_block->info = NodeFindIdent(node);
        }
        CFGBuilder_visitCall(cfgBuilder, node);
        return;
    }
    else if (strcmp(node->type, "listStatement") == 0) {
        int i = 0;
        for (ASTNode* stmt = node; stmt != NULL; stmt = stmt->right) {
            if (stmt->right) {
                CFGBuilder_visit(cfgBuilder, stmt->left, dowhile); // Рекурсивный вызов для левого элемента списка
            }
            else {
                if (dowhile == 1) {
                    CFGBuilder_visitDoWhileEnd(cfgBuilder, stmt->left);
                }
                else
                    CFGBuilder_visitEnd(cfgBuilder, stmt->left);
            }
        }
    }
    else {
        next(cfgBuilder, node, dowhile);
    }
}

CFG* CFGBuilder_build(CFGBuilder* cfgBuilder, char* procedureName, ASTNode* node, int nextId) {
    cfgBuilder->current_id = nextId;
    cfgBuilder->current_block = CFGBuilder_newBlock(cfgBuilder, "", node, "");
    cfgBuilder->cfg = NewCFG(procedureName, cfgBuilder->current_block);

    CFGBuilder_visit(cfgBuilder, node, 0);

    cfgBuilder->cfg->id = cfgBuilder->current_id;

    return cfgBuilder->cfg;
}

CFG* NewCFG(char* procedureName, Block* entryblock) {
    CFG* cfg = malloc(sizeof(CFG));

    cfg->procedureName = procedureName;
    cfg->entryblock = entryblock;
    cfg->cfgLinkList = NewCFGLinkList();

    return cfg;
}

void Block_print(Block* block, FILE* f) {
    if (block->info != NULL) {
        fprintf(f, "\"%d. %s\"", block->id, block->info);
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

CFG* makeCFG(ProcessedFunc* pf, int nextId) {
    CFGBuilder* cfgBuilder = malloc(sizeof(CFGBuilder));
    CFGBuilder_init(cfgBuilder);

    CFG* cfg = CFGBuilder_build(cfgBuilder, pf->identifier, pf->body, nextId);

    return cfg;
}

CFGLinkList* NewCFGLinkList() {
    CFGLinkList* list = malloc(sizeof(CFGLinkList));

    list->links = malloc(sizeof(CFGLink*) * 1024);
    list->count = 0;

    return list;
}

void addNewCFGLink(CFG* cfg, char* funcName) {
    for (int i = 0; i < cfg->cfgLinkList->count; i++) {
        if (strcmp(cfg->cfgLinkList->links[i]->linkedCFGName, funcName) == 0) {
            cfg->cfgLinkList->links[i]->callCount++;
            return;
        }
    }

    CFGLink* cfgLink = malloc(sizeof(CFGLink));
    cfgLink->callCount = 1;
    cfgLink->linkedCFGName = funcName;

    cfg->cfgLinkList->links[cfg->cfgLinkList->count] = cfgLink;
    cfg->cfgLinkList->count++;
}

void printCallGraph(FILE* f, CFG** cfgList, int cfgCount) {
    fprintf(f, "digraph G {label=CallGraph;\n");
    for (int i = 0; i < cfgCount; i++) {
        for (int j = 0; j < cfgList[i]->cfgLinkList->count; j++) {
            char* linkedFuncName = cfgList[i]->cfgLinkList->links[j]->linkedCFGName;
            int callCount = cfgList[i]->cfgLinkList->links[j]->callCount;
            fprintf(f, "\"%s\" -> \"%s\"[label=\"%d\"];\n", cfgList[i]->procedureName, linkedFuncName, callCount);
        }
        if (cfgList[i]->cfgLinkList->count == 0) {
            fprintf(f, "\"%s\"\n", cfgList[i]->procedureName);
        }
    }
    fprintf(f, "}");
}



