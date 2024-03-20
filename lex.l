%option noyywrap
%{
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "main.h"
#include "yacc.tab.h"

using namespace std;

extern	"C"{
	int yylex(void);
	static int yyinput(void);
}

#define LIST     {buf = buf + yytext;}
#define token(t) {LIST; cout << "<" << t << ">" << endl;}
#define tokenInteger(t,i) {LIST; cout << "<" << t << ":" << i << ">" << endl;}
#define tokenNumber(t,f) {LIST; cout << "<" << t << ":" << f << ">" << endl;}	// floating number
#define tokenString(t,s) {LIST; cout << "<" << t << ":" << s << ">" << endl;}	// string

#define MAX_LINE_LENG 256

int linenum = 1;
string k;
string buf;
string stringbuffer;
string upcase = "";

// symbol node
/*typedef struct {
	int number;	// order
	char* ID_name;
	struct symbol* next;
}symbol;

typedef symbol** SymbolTable; //hash table of symbol node

int number = 1;
SymbolTable symboltable = NULL;

SymbolTable create();
void dump(SymbolTable);
int insert(char*, SymbolTable);
int lookup(char*, SymbolTable);*/

%}

delimiters [.,:;\(\)\[\]\{\}]
arithmetic_operator "+"|"-"|"*"|"/"
remainder "mod"
assignment ":="
relational_operator "<"|"<="|">="|">"|"="|"not="
logical_operator "and"|"or"|"not"
keyword "array"|"begin"|"bool"|"char"|"const"|"decreasing"|"default"|"do"|"else"|"end"|"exit"|"false"|"for"|"function"|"get"|"if"|"int"|"loop"|"of"|"put"|"procedure"|"real"|"result"|"return"|"skip"|"string"|"then"|"true"|"var"|"when"
digs [0-9]+
letter [a-zA-Z]
integer [-]?{digs}+
number {integer}"."{digs}
id [a-zA-Z][a-zA-Z0-9]*

%x string
%x annotation

%%
"."	{token(yytext); return DOT;}
","	{token(yytext); return COMMA;}
":"	{token(yytext); return COLON;}
";"	{token(yytext); return SEMICOLON;}
"("	{token(yytext); return LP;}
")"	{token(yytext); return RP;}
"["	{token(yytext); return LMB;}
"]"	{token(yytext); return RMB;}
"{"	{token(yytext); return LB;}
"}"	{token(yytext); return RB;}
"mod"	{token(yytext); return MOD;}
":="	{token(yytext); return ASSIGN;}
"+"	{token(yytext); return ADD;}
"-"	{token(yytext); return SUB;}
"*"	{token(yytext); return MUL;}
"/"	{token(yytext); return DIV;}
"<"	{token(yytext); return LT;}
"<="	{token(yytext); return LET;}
">="	{token(yytext); return GETH;}
">"	{token(yytext); return GT;}
"="	{token(yytext); return EQ;}
"not="	{token(yytext); return NEQ;}
"and"	{token(yytext); return AND;}
"or"	{token(yytext); return OR;}
"not"	{token(yytext); return NOT;}

"array"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return ARRAY;
	}
"begin"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = ""; 
	return BYG;
	}
"bool"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = ""; 
	return BOOL;
	}
"char"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return CHAR;
	}
"const"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return CONST;
	}
"decreasing"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return DECREASING;
	}
"default"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return DEFAULT;
	}
"do"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return DO;
	}
"else"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return ELSE;
	}
"end"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return END;
	}
"exit"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return EXIT;
	}
"false"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	yylval.bool_val = false;
	return BOOLEAN;
	}
"for"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return FOR;
	}
"function"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return FUNCTION;
	}
"get"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return GET;
	}
"if"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return IF;
	}
"int"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return INT;
	}
"loop"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return LOOP;
	}
"of"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return OF;
	}
"put"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return PUT;
	}
"procedure"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return PROCEDURE;
	}
"real"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return REAL;
	}
"result"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return RESULT;
	}
"return"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return RETURN;
	}
"skip"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return SKIP;
	}
"string"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return STR;
	}
"then"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return THEN;
	}
"true"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	yylval.bool_val = true;
	return BOOLEAN;
	}
"var"	{
	upcase  = upcase + yytext; 
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return VAR;
	}
"when"	{
	upcase  = upcase + yytext;  
	int i = 0; 
	while(upcase[i]) {
	upcase[i] = toupper(upcase[i]);
	i++; 
	}
	token(upcase);
	upcase = "";
	return WHEN;
	}
		
{integer}	{
	tokenInteger("Integer", atoi(yytext));
	yylval.int_val = atoi(yytext);
	return INTEGER;
	}

{number}	{
	tokenNumber("Real", atof(yytext));
	yylval.float_val = atof(yytext);
	return FLOAT;
	}
		
{id}	{	// 
	tokenString("ID", yytext);
	yylval.variable = yytext;
	return IDENTIFIER;
	/*char* id = malloc(sizeof(char) * yyleng);
	strcpy(id, yytext);
	
	if(lookup(id,symboltable) == 77777){
		insert(id,symboltable);
	}
	else{
		printf("is already in the symbol table\n");
	}*/
	}

"{%"	{LIST;BEGIN(annotation);}	// start 
<annotation>"%}"	{LIST;BEGIN(INITIAL);}	// end
<annotation>"\n"	{	// change line
	LIST;
	cout << linenum << " : " << buf << endl;
	buf = "";
	linenum++;
	}
<annotation>.	{LIST;}	// any content

		
"%"	{	// one line
	LIST;
	char c = yyinput();
	while(c != '\n'){
		buf += c;
		c = yyinput();
  	}
  	cout << linenum++ << ":" << buf << endl;
        buf = "";
	/*buf = buf + "%";
	char temp;
	while((temp = yyinput()) != '\n'){	// if didn't have change line
		k[0] = temp;
		buf = buf + k;
	}
	//printf("%d : %s\n", linenum, buf);
	linenum++;
	buf = "";*/
	}
		
\"			{LIST;BEGIN(string);}	// start
<string>\n		{	// without change line situation
			//printf("%d : %s", linenum, buf); 
			printf("Not in condition\n");
			exit(0);
			}
<string>\"\"		{LIST; stringbuffer = stringbuffer + "\"";}	// double "" in the middle of string
<string>[ \t]*		{	// space or tab
			LIST;
			stringbuffer = stringbuffer + yytext;
			}
<string>[^\"]*		{	
			LIST;
			stringbuffer = stringbuffer + yytext;
			}
<string>\"		{
			tokenString("String", stringbuffer);
			yylval.str_val = stringbuffer;
			stringbuffer = "";
			BEGIN(INITIAL);
			return STRING;
			}
			
<<EOF>>	{	
		cout << endl;
		cout << "This is the end of parsing" << endl;
		symbol_table.dump(0);
		exit(0);
		}

\n      {
        LIST;
        cout << linenum++ << ":" << buf << endl;
        buf = "";
        }

[ \t]*  {LIST;}

.       {
        LIST;
        cout << linenum + 1 << ":" << buf << endl;
        cout << "bad character: " << buf << endl;
        exit(-1);
        }

%%

















