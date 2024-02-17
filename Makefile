build: run

clean:
	rm -rf *.o result

rebuild: clean build

lex.yy.c: lexer.l
	flex lexer.l

error.o: error.c
	gcc -c -o error.o error.c

cfg.o: cfg.c
	gcc -c -o cfg.o cfg.c

parser.tab.c: parser.y
	bison -d -t parser.y

main.o: main.c
	gcc -c -o main.o main.c

ast.o: ast.c
	gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c -o parser.tab.o parser.tab.c

result: ast.o parser.tab.o lex.yy.o main.o error.o cfg.o
	gcc main.o parser.tab.o lex.yy.o ast.o error.o cfg.o -o result && chmod +x result

run: result
	./result input.txt input2.txt
#	./result input.txt > output.txt && iconv -f ISO-8859-1 -t utf-8 output.txt > utf8_output.txt && cat utf8_output.txt | graph-easy --html --output result_tree.html