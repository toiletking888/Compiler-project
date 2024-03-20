%{
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include "main.h"

using namespace std;
extern "C"{
	void yyerror(string s);
	extern int yylex(void);
}

Symbol_Table symbol_table;

vector<array_range> range;
int error = 0;
%}

/* tokens */
%token ASSIGN
%token DOT COMMA COLON SEMICOLON LP RP LMB RMB LB RB
%token MOD ADD SUB MUL DIV LT LET GETH GT EQ NEQ AND OR NOT
%token ARRAY BYG BOOL CHAR CONST DECREASING DEFAULT DO ELSE END EXIT FAL FOR FUNCTION GET IF INT LOOP OF PUT PROCEDURE REAL RESULT RETURN SKIP STR THEN TRU VAR WHEN
%token <int_val> INTEGER
%token <float_val> FLOAT
%token <bool_val> BOOLEAN
%token <variable> IDENTIFIER
%token <str_val> STRING

%type <expr_result> expressions operand_expression operand_term  const_expression boolean_expression procedure_invocation
%type <typical_type> type
%type <argument_list> arguments formal_arguments args

%left OR
%left AND
%left NOT
%left LT LET GT GETH EQ NEQ
%left ADD SUB
%left MUL DIV MOD
%nonassoc UMINUS
%%

init		: program	{ cout << "start" << endl;}
		;
				
program	: %empty /*empty*/    {cout << "Empty file !!!" << endl;}
		| declarations
		| statement_sequence	
		| declarations program
		| statement_sequence program
		;
		
declarations	: const_declarations 
		| array_declarations
		| variable_declarations
		| function_declarations
		| procedure_declarations
		;
		
type	: STR	{$$ = 0;}
	| INT	{$$ = 1;}
	| REAL	{$$ = 2;}
	| BOOL	{$$ = 3;}
	;
		
function_declarations	: FUNCTION IDENTIFIER LP	{symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);} 
							formal_arguments  RP COLON type 	{
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $8;
											temp.Symbol_type = 0;
											temp.argument_type = $5;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
										} 
											description END IDENTIFIER	{
											//vector<vector<symbol_node> >::iterator it;
											//it = symbol_table.symboltable.begin() + symbol_table.table_index;
											symbol_table.dump(symbol_table.table_index);
											//symbol_table.symboltable.erase(it);
											}
			| FUNCTION IDENTIFIER LP {symbol_table.create(); }/* empty */ RP COLON type {
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $7;
											temp.Symbol_type = 0;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
										}
										description END IDENTIFIER	{
										//vector<vector<symbol_node> >::iterator it;
										//it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										//symbol_table.symboltable.erase(it);
										}
			| FUNCTION IDENTIFIER LP {symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);} formal_arguments  RP COLON type 						{
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $8;
											temp.Symbol_type = 0;
											temp.argument_type = $5;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
											}
											/* empty */ END IDENTIFIER	{
											//vector<vector<symbol_node> >::iterator it;
											//it = symbol_table.symboltable.begin() + symbol_table.table_index;
											symbol_table.dump(symbol_table.table_index);
											//symbol_table.symboltable.erase(it);
											}
			| FUNCTION IDENTIFIER LP {symbol_table.create();} /* empty */ RP COLON type {
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $7;
											temp.Symbol_type = 0;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
										}
										/* empty */ END IDENTIFIER	{
										//vector<vector<symbol_node> >::iterator it;
										//it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										//symbol_table.symboltable.erase(it);
										}
			;

procedure_declarations	: PROCEDURE IDENTIFIER LP {symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);} formal_arguments RP 							{ 
									vector<int> where;
									where = symbol_table.ALL_lookup($2);
									if(where.empty()){
										symbol_node temp;
										temp.name = $2;
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										temp.argument_type = $5;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									}
									description END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
			| PROCEDURE IDENTIFIER LP {symbol_table.create();} /* empty */ RP { 
									vector<int> where;
									where = symbol_table.ALL_lookup($2);
									if(where.empty()){
										symbol_node temp;
										temp.name = $2;
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									}
									description END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
			| PROCEDURE IDENTIFIER LP {symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);} formal_arguments RP 							{ 
									vector<int> where;
									where = symbol_table.ALL_lookup($2);
									if(where.empty()){
										symbol_node temp;
										temp.name = $2;
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										temp.argument_type = $5;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									} 
									/* empty */ END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
			| PROCEDURE IDENTIFIER	LP {symbol_table.create();} /* empty */ RP {
									vector<int> where;
									where = symbol_table.ALL_lookup($2);
									if(where.empty()){
										symbol_node temp;
										temp.name = $2;
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									}
									/* empty */ END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
			;


formal_arguments	: %empty	{vector<int> temp; $$ = temp;}
			| args	{$$ = $1;}
			;
			
args			: IDENTIFIER COLON type	{
							vector<int> temp;
							temp = $$;
							temp.push_back($3);
							symbol_node node;
							node.name = $1;
							node.type = $3;
							node.Symbol_type = 3;
							symbol_table.insert(node);
							$$ = temp;						
							}
			| IDENTIFIER COLON type COMMA args	{
								vector<int> temp;
								temp = $5;
								temp.push_back($3);
								/*for(int i = 0;i < temp.size();i++){
									cout << temp[i] << " | ";
								}
								cout << endl;*/
								symbol_node node;
								node.name = $1;
								node.type = $3;
								node.Symbol_type = 3;
								symbol_table.insert(node);
								$$ = temp;
								}
			;
						
const_declarations	: CONST IDENTIFIER COLON type ASSIGN const_expression	{ 
											if(symbol_table.scope_lookup(symbol_table.table_index,$2)== 99999){
												if ($4 == $6.type){
													if($6.isNotVariable){
														symbol_node temp;
														temp.name = $2;
														temp.content = $6.content;
														temp.type = $4;
														temp.Symbol_type = 2;
														symbol_table.insert(temp);
													}	
													else{
														yyerror("can't assign variable to const");
													}
												}
												else{
													yyerror("CONST TYPE ERROR");
												}
											}
											else{
												yyerror("this id is already exist(const)");
											}
											}
			| CONST IDENTIFIER ASSIGN const_expression	{
									if(symbol_table.scope_lookup(symbol_table.table_index,$2) == 99999){
										if($4.isNotVariable){
											symbol_node temp;
											temp.name = $2;
											temp.content = $4.content;
											temp.type = $4.type;
											temp.Symbol_type = 2;
											symbol_table.insert(temp);
										}
										else{
											yyerror("can't assign variable to const");
										} 
									}
									else{
										yyerror("this id is already exist(const)");
									}
									}
			;
			
variable_declarations	: VAR IDENTIFIER ASSIGN const_expression	{ 
									if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
										symbol_node temp;
										temp.name = $2;
										temp.content = $4.content;
										temp.type = $4.type;
										temp.Symbol_type = 3;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(var)");
									}						
									}
			| VAR IDENTIFIER COLON type ASSIGN const_expression	{
									if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
										if ($4 == $6.type){
											symbol_node temp;
											temp.name = $2;
											temp.content = $6.content;
											temp.type = $4;
											temp.Symbol_type = 3;
											symbol_table.insert(temp);
										}
										else{	
											//cout << $4 << " " << $6.type;
											yyerror("VARIABLE TYPE ERROR");
										}
									}
									else{
										yyerror("this id is already exist(var)");
									}
									}
			| VAR IDENTIFIER COLON type	{ 
							if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
								symbol_node temp;
								temp.name = $2;
								temp.type = $4;
								temp.Symbol_type = 3;
								symbol_table.insert(temp);
							}
							else{
								yyerror("this id is already exist(var)");
							}
							}
			;

array_declarations	: VAR IDENTIFIER COLON ARRAY INTEGER DOT DOT INTEGER OF type	{ 
											if(symbol_table.scope_lookup(symbol_table.table_index ,$2) == 99999){
												symbol_node temp;
												temp.name = $2;
												temp.type = $10;
												temp.Symbol_type = 4;
												symbol_table.insert(temp);
												array_range tempp;
												tempp.array_name = $2;
												tempp.start = $5;
												tempp.end = $8;
												range.push_back(tempp);
											}
											else{
												yyerror("this id is already exist(array)");
											}
											}
			;
			
statement_sequence	: statements
			| statements statement_sequence
			;
			
statements	: block	
		| simple	
		| conditional	
		| loop	
		| procedure_invocation	
		;

block	: BYG {symbol_table.create();} description END {
						vector<vector<symbol_node> >::iterator it;
						it = symbol_table.symboltable.begin() + symbol_table.table_index;
						symbol_table.dump(symbol_table.table_index);
						symbol_table.symboltable.erase(it);
						}
	| BYG {symbol_table.create();} variable_declarations END {
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
							}
	| BYG {symbol_table.create();} const_declarations END {
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
							}	
	| BYG /* empty */ END
	;
	
simple	: IDENTIFIER ASSIGN expressions	{
						if(!symbol_table.ALL_lookup($1).empty())	{
							// keep doing
						}
						else{
							yyerror("Variable didn't exist.");
						}				
						}
	| IDENTIFIER LMB expressions RMB ASSIGN expressions	{
								if(!symbol_table.ALL_lookup($1).empty()){
									// keep doing
								}
								else{
									yyerror("Array didn't exist.");
								}
								}
	| PUT expressions	
	| GET IDENTIFIER
	| RESULT expressions
	| RETURN
	| EXIT WHEN boolean_expression
	| EXIT
	| SKIP 
	;

expressions	: operand_expression	{$$ = $1;}
		| LP expressions RP	{$$ = $2;}
		| operand_expression LT operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) < stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) < stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		| operand_expression LET operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) <= stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) <= stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		| operand_expression EQ operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) == stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) == stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else if($1.type == 3 && $3.type == 3){ // compare boolean
									temp.type = 3;
									bool i1,i2;
									if($1.isNotVariable && $3.isNotVariable){
										if($1.content == "true"){
											i1 = true;
										}
										else{
											i1 = false;
										}
										if($3.content == "true"){
											i2 = true;
										}
										else{
											i2 = false;
										}
										if(i1 == i2){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if($1.type == 0 && $3.type == 0){ // compare string
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if($1.content == $3.content){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		| operand_expression GETH operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) >= stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) >= stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		| operand_expression GT operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) > stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) > stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		| operand_expression NEQ operand_expression	{
								expr_term temp;
								if($1.type == 1 && $3.type == 1){ // compare int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stoi($1.content) != stoi($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if(stof($1.content) != stof($3.content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else if($1.type == 3 && $3.type == 3){ // compare boolean
									temp.type = 3;
									bool i1,i2;
									if($1.isNotVariable && $3.isNotVariable){
										if($1.content == "true"){
											i1 = true;
										}
										else{
											i1 = false;
										}
										if($3.content == "true"){
											i2 = true;
										}
										else{
											i2 = false;
										}
										if(i1 != i2){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else if($1.type == 0 && $3.type == 0){ // compare string
									temp.type = 3;
									if($1.isNotVariable && $3.isNotVariable){
										if($1.content != $3.content){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
		;

operand_expression	: operand_term	{$$ = $1;}
			| operand_expression OR operand_expression	{
									expr_term temp;
									if($1.type == 3 && $3.type == 3){
										temp.type = 3;
										bool i1, i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 || i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type error");
									}
									$$ =  temp;
									}
			| operand_expression AND operand_expression	{
									expr_term temp;
									if($1.type == 3 && $3.type == 3){
										temp.type = 3;
										bool i1, i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 && i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type error");
									}
									$$ =  temp;
									}
			| NOT operand_expression	{
							expr_term temp = $2;
							if($2.type == 3){
								temp.type = 3;
								if($2.isNotVariable){
									if($2.content == "true"){
										temp.content = "false";
									}		
									else{
										temp.content = "true";
									}
								}
							}
							else{
								yyerror("Content type error");
							}
							$$ =  temp;
							}
			| operand_expression ADD operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) + stoi($3.content));
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){
										temp.type = 2;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stof($1.content) + stof($3.content));
										}
									}
									else if($1.type == 0 && $3.type == 0){
										temp.type = 0;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = $1.content + $3.content;
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression SUB operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) - stoi($3.content));
										}	
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){
										temp.type = 2;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stof($1.content) - stof($3.content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression MUL operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) * stoi($3.content));
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){
										temp.type = 2;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stof($1.content) * stof($3.content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression DIV operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) / stoi($3.content));
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){
										temp.type = 2;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stof($1.content) / stof($3.content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression MOD operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) % stoi($3.content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| SUB operand_expression %prec UMINUS	{
								expr_term temp;
								if($2.type == 1){
									temp.type = 1;
									if($2.isNotVariable){
										temp.content = to_string(stoi($2.content) * (-1));
									}
								}
								else if($2.type == 2){
									temp.type = 2;
									if($2.isNotVariable){
										temp.content = to_string(stof($2.content) * (-1));
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								$$ = temp;
								}
			;
			
procedure_invocation	: IDENTIFIER LP arguments RP	{
									vector<int> where;
									for(int i = 0;i < symbol_table.argument_place.size();i++){
										for(int j = 0;j < symbol_table.symboltable[i].size();j++){
											if(!symbol_table.ALL_lookup($1).empty()){
												where = symbol_table.ALL_lookup($1);
												break;
											}
											else{
											
											}
										}
									}
									if(where.empty()){
										yyerror("Identifier not found");
									}
									else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){
										yyerror("Is not function name");
									}
									else{
										bool Same = true;
		       							if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == $3.size()){
		                							for(int i = 0;i < $3.size();i++){
		                    								if(symbol_table.symboltable[where[0]][where[1]].argument_type[i] != $3[i]){
		                    	    								Same=false;
		                        								break;
		                    								}
		                							}
		            							}
		            							else{
		                							Same=false;
		            							}
		            							if(Same){
		                							expr_term temp;
		                							temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		                							temp.isNotVariable = false;
		               							$$ = temp;
		            							}
		            							else{
		                							yyerror("argument type didn't match");
		            							}
									}									
									}
			| IDENTIFIER LP /* empty */ RP	{
								vector<int> where;
								for(int i = 0;i < symbol_table.argument_place.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup($1).empty()){
											where = symbol_table.ALL_lookup($1);
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){ 
		         				   		yyerror("Identifier not found");
		        					}
		        					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){ 
		            						yyerror("Is not function name");
		        					}
		        					else{
		            						if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == 0){
		                						expr_term temp;
		                						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		                						temp.isNotVariable = false;
		                						$$ = temp;
		            						}
		            						else{
		                						yyerror("The function had some arguemts");
		            						}
		        					}
								}
			;
			
operand_term	: IDENTIFIER LP arguments RP	{ // function invocation with argument
								vector<int> where;
								for(int i = 0;i < symbol_table.symboltable.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										//cout << symbol_table.symboltable[i][j].name << endl;
										//cout << $1 << endl;
										if(!symbol_table.ALL_lookup($1).empty()){
											where = symbol_table.ALL_lookup($1);
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){
									yyerror("Identifier not found");
								}
								else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){
									//cout << symbol_table.symboltable[temp_index][where].name << endl;
									yyerror("Is not function name");
								}
								else{
									bool Same = true;
									cout << symbol_table.symboltable[where[0]][where[1]].argument_type.size() << " ||||| " << $3.size() << endl;
               							if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == $3.size()){
                        							for(int i = 0;i < $3.size();i++){
                            								if(symbol_table.symboltable[where[0]][where[1]].argument_type[i] != $3[i]){
                            	    								Same=false;
                                								break;
                            								}
                        							}
                    							}
                    							else{	
                    								
                        							Same=false;
                    							}
                    							if(Same){
                        							expr_term temp;
                        							temp.type = symbol_table.symboltable[where[0]][where[1]].type;
                        							temp.isNotVariable = false;
                       							$$ = temp;
                    							}
                    							else{
                        							yyerror("argument didn't match");
                    							}
								}
								}	
		| IDENTIFIER LP /* empty */ RP	{ // function invocation
							vector<int> where;
							for(int i = 0;i < symbol_table.argument_place.size();i++){
								for(int j = 0;j < symbol_table.symboltable[i].size();j++){
									if(!symbol_table.ALL_lookup($1).empty()){
										where = symbol_table.ALL_lookup($1);
										break;
									}
									else{
										
									}
								}
							}
							if(where.empty()){ 
                 				   		yyerror("Identifier not found");
                					}
                					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){ 
                    						yyerror("Is not function name");
                					}
                					else{
                    						if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == 0){
                        						expr_term temp;
                        						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
                        						temp.isNotVariable = false;
                        						$$ = temp;
                    						}
                    						else{
                        						yyerror("The function had some arguemts");
                    						}
                					}
							}	
		| IDENTIFIER LMB operand_expression RMB	{ // array
								vector<int> where;
								int index;
								for(int i = 0;i < symbol_table.symboltable.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup($1).empty()){
											where = symbol_table.ALL_lookup($1);
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){
									yyerror("Identifier not found");
								}
								else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 4){
									yyerror("Is not an arrry");
								}
								else{	
									for(int i = 0;i < range.size();i++){
										if(range[i].array_name == $1){
											index = i;
											break;
										}
									}	
									if($3.isNotVariable){ 
                								if($3.type == 1){
                									if((stoi($3.content) < range[index].start) || (stoi($3.content) > range[index].end)){
                												yyerror("index out of array range");									
                									}
                									else{
		        									expr_term temp;
		            									temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		            									temp.isNotVariable = false;
		            									$$ = temp;
                									}
                								}
                								else{
                    									yyerror("Index need to be int");
                								}
            								}
            								else{ 
                								yyerror("Index can't not be variable");
            								}
								}
								}
		| LP operand_expression RP	{$$ = $2;}
		| STRING	{ 
				expr_term temp;
				temp.type = 0;
				temp.isNotVariable = true;
				temp.content = $1;
				$$ = temp;
				}	
		| INTEGER	{
				expr_term temp;
				temp.type = 1;
				temp.isNotVariable = true;
				temp.content = to_string($1);
				$$ = temp;
				}
		| FLOAT	{
				expr_term temp;
				temp.type = 2;
				temp.isNotVariable = true;
				temp.content = to_string($1);
				$$ = temp;
				}
		| BOOLEAN	{
				expr_term temp;
				temp.type = 3;
				temp.isNotVariable = true;
				if($1 == true){
					temp.content = "true";
				}
				else{
					temp.content = "false";
				}
				$$ = temp;
				}
		| IDENTIFIER	{
				expr_term temp;
				vector<int> where = symbol_table.ALL_lookup($1);
				if(where.empty()){
					yyerror("Identifier not found");
				}
				else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 2 && symbol_table.symboltable[where[0]][where[1]].Symbol_type != 3){
					yyerror("Identifier wrong type");
				}
				else{
					temp.type = symbol_table.symboltable[where[0]][where[1]].type;
					if(symbol_table.symboltable[where[0]][where[1]].Symbol_type == 3){
						temp.isNotVariable = false;
					}
					else{
						temp.isNotVariable = true;
						temp.content = symbol_table.symboltable[where[0]][where[1]].content;
					}
				}
				$$ = temp;
				}
		;

arguments	: expressions	{
					vector<int> temp;
					temp.push_back($1.type);
					cout << $1.type << endl;
					$$ = temp;
					}
			| expressions COMMA arguments	{
									vector<int> temp;
									temp = $3;
									temp.push_back($1.type);
									/*for(int i = 0;i < temp.size();i++){
										cout << temp[i] << " ";
									}
									cout << endl;*/
									$$ = temp;
									}
			;

conditional	: {symbol_table.create();} IF boolean_expression  {
					if($3.type != 3){
						yyerror("Condition wrong type");
					}					
					} THEN  description ELSE description END IF	{
														vector<vector<symbol_node> >::iterator it;
														it = symbol_table.symboltable.begin() + symbol_table.table_index;
cout << "number:::::: "<<symbol_table.table_index << endl;
														symbol_table.dump(symbol_table.table_index);
														symbol_table.symboltable.erase(it);
														}
		| {symbol_table.create();} IF boolean_expression {
					if($3.type != 3){
						yyerror("Condition wrong type");
					}
					}THEN  description END IF	{
												vector<vector<symbol_node> >::iterator it;
												it = symbol_table.symboltable.begin() + symbol_table.table_index;
												symbol_table.dump(symbol_table.table_index);
												symbol_table.symboltable.erase(it);
												}
		;
		
boolean_expression	: LP boolean_expression RP	{$$ = $2;}
			| operand_expression LT operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) < stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}							
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) < stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression LET operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) <= stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) <= stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression EQ operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) == stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) == stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else if($1.type == 3 && $3.type == 3){ // compare boolean
										temp.type = 3;
										bool i1,i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 == i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if($1.type == 0 && $3.type == 0){ // compare string
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == $3.content){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression GETH operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) >= stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) >= stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression GT operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) > stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ //compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) > stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;						
									}
			| operand_expression NEQ operand_expression	{
									expr_term temp;
									if($1.type == 1 && $3.type == 1){ // compare int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stoi($1.content) != stoi($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if(($1.type == 1 || $1.type == 2) && ($3.type == 1 || $3.type == 2)){ // compare float or int
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if(stof($1.content) != stof($3.content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else if($1.type == 3 && $3.type == 3){ // compare boolean
										temp.type = 3;
										bool i1,i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 != i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else if($1.type == 0 && $3.type == 0){ // compare string
										temp.type = 3;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content != $3.content){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									$$ = temp;
									}
			| operand_expression OR operand_expression	{
									expr_term temp;
									if($1.type == 3 && $3.type == 3){
										temp.type = 3;
										bool i1, i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 || i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									$$ =  temp;
									}
			| operand_expression AND operand_expression	{
									expr_term temp;
									if($1.type == 3 && $3.type == 3){
										temp.type = 3;
										bool i1, i2;
										if($1.isNotVariable && $3.isNotVariable){
											if($1.content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if($3.content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 && i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									$$ =  temp;
									}
			| NOT operand_expression	{
							expr_term temp = $2;
							if($2.type == 3){
								temp.type = 3;
								if($2.isNotVariable){
									if($2.content == "true"){
										temp.content = "false";
									}		
									else{
										temp.content = "true";
									}
								}
							}
							else{
								yyerror("Boolean expression wrong type");
							}
							$$ =  temp;
							}
			| IDENTIFIER	{
					expr_term temp;
					vector<int> where = symbol_table.ALL_lookup($1);
					if(where.empty()){
						yyerror("Identifier not found");
					}
					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 2 && symbol_table.symboltable[where[0]][where[1]].Symbol_type != 3){
						yyerror("Identifier wrong type");
					}
					else if(symbol_table.symboltable[where[0]][where[1]].type != 3){
						yyerror("Boolean expression wrong type");
					}
					else{
						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
						if(symbol_table.symboltable[where[0]][where[1]].Symbol_type == 3){
							temp.isNotVariable = false;
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[where[0]][where[1]].content;
						}
					}
					$$ = temp;
					}
			| BOOLEAN	{
					expr_term temp;
					temp.type = 3;
					temp.isNotVariable = true;
					if($1 == true){
						temp.content = "true";
					}
					else{
						temp.content = "false";
					}
					$$ = temp;
					}
			;

description	: const_declarations description
		| variable_declarations description
		| statement_sequence description
		| %empty /* empty */
		;

loop	: {symbol_table.create(); } LOOP description END LOOP	{
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
								}
	| {symbol_table.create();} FOR DECREASING IDENTIFIER COLON const_expression DOT DOT const_expression {
							if(stoi($6.content) < stoi($9.content)){
								yyerror("For loop scope is not decreasing sequence");
							}
							else{
								/*vector<int> where;
								for(int i = 0;i < symbol_table.argument_place.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup($4).empty()){
											where = symbol_table.ALL_lookup($4);
											break;
										}
										else{
											
										}
									}
								}*/
								if($6.type == 1 && $9.type == 1){
									symbol_node temp;
									temp.name = $4;
									temp.type = 1;
									temp.Symbol_type = 3;
									symbol_table.insert(temp);
								}
								else{
									yyerror("range type must be integer");
								}
								
							}
							} 
							description END FOR	{
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
	|  FOR {symbol_table.create();} IDENTIFIER COLON const_expression DOT DOT const_expression{
							if($5.type == 1 && $8.type == 1){
								symbol_node temp;
								temp.name = $3;
								temp.type = 1;
								temp.Symbol_type = 3;
								symbol_table.insert(temp);
							}
							else{
								yyerror("range type must be integer");
							}
							}
										description END FOR {
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
;

const_expression	: STRING	{
					expr_term temp;
					temp.type = 0;
					temp.isNotVariable = true;
					temp.content = $1;
					$$ = temp;
					}
			| INTEGER	{
					expr_term temp;
					temp.type = 1;
					temp.isNotVariable = true;
					temp.content = to_string($1);
					$$ = temp;
					}
			| FLOAT	{
					expr_term temp;
					temp.type = 2;
					temp.isNotVariable = true;
					temp.content = to_string($1);
					$$ = temp;
					}
			| BOOLEAN	{
					expr_term temp;
					temp.type = 3;
					temp.isNotVariable = true;
					if($1 == true){
						temp.content = "true";
					}
					else{
						temp.content = "false";
					}
					$$ = temp;
					}
			| IDENTIFIER	{
					expr_term temp;
					vector<int> where = symbol_table.ALL_lookup($1);
					if(where.empty()){
						yyerror("Identifier not found");
					}
					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 2 && symbol_table.symboltable[where[0]][where[1]].Symbol_type != 3){
						yyerror("Identifier wrong type");
					}
					else{
						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
						if(symbol_table.symboltable[where[0]][where[1]].Symbol_type == 3){
							temp.isNotVariable = false;
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[where[0]][where[1]].content;
						}
					}
					$$ = temp;
					}
			;
%%
void yyerror(string s){
    cout<< "Line number: " << linenum << endl;
    fprintf(stderr, "%s\n", s.c_str());
    error++;
    exit(0);
}

int main( int argc, char **argv ){
	symbol_table.create();
	FILE* input;
	extern FILE* yyin;
	++argv, --argc;
	//--- File input ---//
	if ( argc > 0 ){
		input = fopen(argv[0],"r");
		
        	if(input==NULL){
          		printf("cannot open file\n");
            		return -1;
		}
		yyin = input;
	}
	//--- Stdin ---//
	else{
		cout << "!!!!!!!fsdgragre" << endl;
	}
    	yyparse();
  
    	if ( argc > 0 ){
        	fclose(input);
    	}
	return 0;
}
