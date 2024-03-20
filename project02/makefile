yacc: lex.yy.o yacc.tab.o
	g++ -o yacc lex.yy.o yacc.tab.o

yacc.tab.o: yacc.y main.h
	bison -v -d yacc.y
	g++ -c yacc.tab.c

lex.yy.o: lex.l yacc.tab.o main.h
	lex lex.l
	g++ -c lex.yy.c

clean:
	rm -f *.o lex.yy.c yacc.tab.c yacc.tab.h yacc

