%{
#include "error.h"
#include "parser.tab.h"
#include <string.h>
%}


%%

[0-9]+ {
    yylval.node = createNode("DEC", yytext, NULL, NULL);
    return DEC;
}
\"[^\"\\]*(?:\\.[^\"\\]*)*\" {
    char buff[1024];
    strncpy(buff, yytext+1, strlen(yytext)-2);
    buff[strlen(buff)-1] = 0;
    yylval.node = createNode("STR", buff, NULL, NULL);
    return STR;
}
'[^']' {
    char buff[1];
    strncpy(buff, yytext+1, 1);
    yylval.node = createNode("CHAR", buff, NULL, NULL);
    return CHAR;
}
\[,*\] {
    yylval.node = createNode("ARRAY_COMMAS", yytext, NULL, NULL);
    return ARRAY_COMMAS;
}

0[xX][0-9A-Fa-f]+ {
    char* buff = malloc(256);
    sprintf(buff, "%d", strtol(yytext + 2, NULL, 16));
    yylval.node = createNode("HEX", buff, NULL, NULL);
    return HEX;
}
0[bB][01]+ {
    char* buff = malloc(256);
    sprintf(buff, "%d", strtol(yytext + 2, NULL, 2));
    yylval.node = createNode("BIN", buff, NULL, NULL);
    return BIN;
}
"byte" {
           yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"int" {
          yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
          return TYPEDEF;
      }
"uint" {
           yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"long" {
           yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"bool" {
           yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"ulong" {
            yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
            return TYPEDEF;
        }
"char" {
           yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"string"  {
              yylval.node = createNode("TYPEDEF", yytext, NULL, NULL);
              return TYPEDEF;
          }
"if"  {
 yylval.node = createNode("IF", "", NULL, NULL);
 return IF;
 }
"else"  {
 yylval.node = createNode("ELSE", "", NULL, NULL);
 return ELSE;
 }
"do"  {
 yylval.node = createNode("DO", "", NULL, NULL);
 return DO;
 }
"while"  {
 yylval.node = createNode("WHILE", "", NULL, NULL);
 return WHILE;
 }
"break"  {
 yylval.node = createNode("BREAK", "", NULL, NULL);
 return BREAK;
 }
"{"  {
 return LBRACE;
 }
"}"  {
 return RBRACE;
 }
"["  {
 return LBRACKET;
 }
"]"  {
 return RBRACKET;
 }
"true"  {
 yylval.node = createNode("TRUE", "", NULL, NULL);
 return TRUE;
 }
"false"  {
 yylval.node = createNode("FALSE", "", NULL, NULL);
 return FALSE;
 }
"%"  {
 return PERCENT;
 }
";"  {
 return SEMICOLON;
 }
","  {
 return COMMA;
 }
"!="  {
 return NOTEQUAL;
 }
"!"   {
 return NOT;
 }
"\|\|"   {
 return OR;
 }
"&&"     {
 return AND;
 }
"+"      {
 return PLUS;
 }
"-"      {
 return MINUS;
 }
"<="     {
 return LESSTHANEQ;
 }
">="     {
 return GREATERTHANEQ;
 }
"<"      {
 return LESSTHAN;
 }
">"      {
 return GREATERTHAN;
 }
"*"      {
 return STAR;
 }
 "/"      {
 return SLASH;
 }
"("      {
 return LPAREN;
 }
")"      {
 return RPAREN;
 }
"="      {
 return EQUAL;
 }
[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.node = createNode("IDENTIFIER", yytext, NULL, NULL);
    return IDENTIFIER;
}
\/\/.*                              { /* Пропустить комментарии */ }
\n                                  { /* Пропустить переводы строк */ }
[ \t]                               { /* Пропустить пробелы и табуляцию */ }
.                                   {
                                        // Обработка нераспознанных символов или ошибок
                                        fprintf(stderr, "Нераспознанный символ: %s\n", yytext);
                                    }

%%


int yywrap() {
    // Your implementation here, typically returning 1 to signal EOF.
    return 1;
}
