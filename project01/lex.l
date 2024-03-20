%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenNumber(t,f) {LIST; printf("<%s,%f>\n", t,f);}	// floating number
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}	// string

#define MAX_LINE_LENG 256

int linenum = 1;
char k[1];
char buf[MAX_LINE_LENG];
char stringbuffer[MAX_LINE_LENG];

// symbol node
typedef struct {
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
int lookup(char*, SymbolTable);

%}

delimiters [.,:;\(\)\[\]\{\}]
arithmetic_operator "+"|"-"|"*"|"/"
remainder "mod"
assignment ":="
relational_operator "<"|"<="|">="|">"|"="|"not="
logical_operator "and"|"or"|"not"
keyword array|begin|bool|char|const|decreasing|default|do|else|end|exit|false|for|function|get|if|int|loop|of|put|procedure|real|result|return|skip|string|then|true|var|when
digs [0-9]+
letter [a-zA-Z]
integer [-]?{digs}+
number {integer}"."{digs}?
id [a-zA-Z][a-zA-Z0-9]*

%x string
%x annotation

%%
{delimiters}	|
{remainder} |
{arithmetic_operator}	|
{assignment} |
{relational_operator} |
{logical_operator} 	{token(yytext);}

{keyword}	{
		char *upcase = malloc(sizeof(char) * yyleng);
		strcpy(upcase, yytext);
		for(int i = 0; i < yyleng; i++){
		upcase[i] = toupper(upcase[i]);
		}
		token(upcase);
		}
		
{integer}	{
	tokenInteger("Integer", atoi(yytext));
		}

{number}	{
	tokenNumber("Real", atof(yytext));
	}
		
{id}	{
	tokenString("ID", yytext);
	char* id = malloc(sizeof(char) * yyleng);
	strcpy(id, yytext);
	if(lookup(id,symboltable) == 77777){
		insert(id,symboltable);
	}
	else{
		printf("is alreeady in the symbol table\n");
	}
	}

"{%"	{LIST;BEGIN(annotation);}	// start 
<annotation>"%}"	{LIST;BEGIN(INITIAL);}	// end
<annotation>"\n"	{	// change line
	LIST;
	printf("%d : %s", linenum, buf);
	buf[0] = '\0';
	linenum++;
	}
<annotation>.	{LIST;}	// any content

		
"%"	{	// one line
	strcat(buf, "%");
	char temp;
	while((temp = input()) != '\n'){	// if didn't have change line
		k[0] = temp;
		strcat(buf, k);
	}
	printf("%d : %s\n", linenum, buf);
	linenum++;
	buf[0] = '\0';
	}
		
\"			{LIST;BEGIN(string);}	// start
<string>\n		{	// without change line situation
			printf("%d : %s", linenum, buf); 
			printf("Not in condition\n");
			exit(0);
			}
<string>\"\"		{LIST; strcat(stringbuffer, "\"");}	// double "" in the middle of string
<string>[ \t]*		{	// space or tab
			LIST;
			strcat(stringbuffer, yytext);
			}
<string>[^\"]*	{	
			LIST;
			strcat(stringbuffer, yytext);
			}
<string>\"		{
			tokenString("String", stringbuffer);
			stringbuffer[0] = '\0';
			BEGIN(INITIAL);
			}
			
<<EOF>>	{	
		printf("\n");
		printf("This is the end of scan.\n");
		printf("\n");
		dump(symboltable);
		free(symboltable);
		exit(0);
		}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }

%%

SymbolTable create() {
	if (symboltable == NULL){
		SymbolTable new_one = malloc(sizeof(symbol*) * 26);	// size of alphabet
		if(new_one == NULL){
			printf("Could not allocate the memory space");
		}
		else{
			for(int i = 0; i < 26; i++){
				new_one[i] = NULL;
			}
			symboltable = new_one;
		}
	}
	return symboltable;
}

void dump(SymbolTable t){
	printf("The contents of Symbol Table: \n");
	for(int i = 0; i < 26; i++){
		if(t[i] != NULL){
			symbol* temp = t[i];
			while(temp){
				printf("%d : %s \n", temp->number, temp->ID_name);
				temp = temp->next;
			}
		}
	}
}

int insert(char* str, SymbolTable t){
	int index = 0;
	index = (toupper(str[0])-65) % 25;
	printf("%c,  Index = %d\n", str[0], index);
	if(t[index] != NULL){
		symbol* new_one = malloc(sizeof(symbol));
		symbol* temp;
		temp = t[index];
		while(temp->next){
			temp = temp->next;
		}
		new_one->number = number;
		printf("%d\n",number);
		new_one->ID_name = str;
		printf("temp: %s\n",temp->ID_name);
		temp->next = new_one;
		printf("new_one in temp: %s\n",temp->ID_name);
		number++;
	}
	else{
		t[index] = malloc(sizeof(symbol));
		t[index]->number = number;
		printf("%d\n",number);
		t[index]->ID_name = str;
		t[index]->next = NULL;
		number++;
	}
	return index;
}

int lookup(char* str, SymbolTable t){
	int index = 0;
	index = (toupper(str[0])-65) % 25;
	if(t[index] == NULL){
		return 77777;
	}
	else{
		symbol* temp;
		temp = t[index];
		while(temp){
			//printf("fadjfhlafhdflldhflahdf\n");
			printf("%s,,,,%s\n",temp->ID_name, str);
			if(strcmp(temp->ID_name, str) == 0){
				//printf("asdcasdcasdcasdca\n");
				printf("This id is already in the SymbolTable\n");
				return temp->number;
			}
			else{
				printf("next\n");
				temp = temp->next;
				//printf("next temp: %s\n", temp->ID_name);
			}
		}
		printf("insert item\n");
		return 77777;
	}
}


int main(int argc, char **argv){
	yyin = fopen(argv[1], "r");
	symboltable = create();
	yylex();
	fclose(yyin);
}
















