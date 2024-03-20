%{
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
#include "main.h"

using namespace std;
extern "C"{
	void yyerror(string s);
	extern int yylex(void);
}

Symbol_Table symbol_table;
fstream output;
vector<array_range> range;
int error = 0;
string className = "example";
bool hasValue = false;
Label label;
bool first = true;
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

init		: program
		;
				
program	: %empty /*empty*/
		| declarations program
		| {
		  if(first){
			output << "class " << className << endl;
			output << "{" << endl;
			output << "method public static void main(java.lang.String[])" << endl;
			output << "max_stack 15"<< endl;
			output << "max_locals 15" << endl;
			output << "{" << endl;
		  }
		  first = false;
		} statement_sequence program {
					output << "}" << endl;
					output << "return" << endl;
					output << "}" << endl;	
					}
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
		
function_declarations	: FUNCTION IDENTIFIER LP {symbol_table.create();} formal_arguments RP COLON type {
										output << "method public static ";
										switch($8){
											case 0:
												output << "java.lang.String ";
												break;
											case 1:
												output << "int ";
												break;
											case 2: 
												output << "float ";
												break;
											case 3: //bool
												output << "int ";
												break;
											default:
												output << "ERROR ";
												break;
										}
										output << $2 << "(";
										vector<int> arg = $5;
										for(int i=0;i<arg.size();i++){
											switch(arg[i]){
												case 0:
													output << "java.lang.String";
													break;
												case 1:
													output << "int";
													break;
												case 2: 
													output << "float";
													break;
												case 3: // bool
													output << "int";
													break;
												default:
													output << "ERROR";
													break;
											}
											if(i != arg.size() - 1){
												output<<", ";
											}
										}
										output << ")" << endl;
									    	output << "max_stack 15" << endl;
									    	output << "max_locals 15" << endl;
										output << "{" << endl;
										
										cout << symbol_table.table_index << endl;
										symbol_table.argument_place.push_back(symbol_table.table_index);
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
											output << "}" << endl;
											//vector<vector<symbol_node> >::iterator it;
											//it = symbol_table.symboltable.begin() + symbol_table.table_index;
											symbol_table.dump(symbol_table.table_index);
											//symbol_table.symboltable.erase(it);
											}
			| FUNCTION IDENTIFIER LP RP COLON type {
								output << "method public static ";
								switch($6){
									case 0:
										output << "java.lang.String ";
										break;
									case 1:
										output << "int ";
										break;
									case 2: 
										output << "float ";
										break;
									case 3: //bool
										output << "int ";
										break;
									default:
										output << "ERROR ";
										break;
								}	
								output << $2 << "()" << endl;
								output << "max_stack 15" << endl;
								output << "max_locals 15" << endl;
								output << "{" << endl;	
								symbol_table.create();
								vector<int> where;
								where = symbol_table.ALL_lookup($2);
								if(where.empty()){
									symbol_node temp;
									temp.name = $2;
									temp.content = "none";
									temp.type = $6;
									temp.Symbol_type = 0;
									symbol_table.insert(temp);
								}
								else{
									yyerror("this id is already exist(function)");
								}
								}
								description END IDENTIFIER	{
								output << "}" << endl;
								//vector<vector<symbol_node> >::iterator it;
								//it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								//symbol_table.symboltable.erase(it);
								}
			/*| FUNCTION IDENTIFIER LP formal_arguments  RP COLON type {
										symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $7;
											temp.Symbol_type = 0;
											temp.argument_type = $4;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
											} deEND IDENTIFIER	{
											//vector<vector<symbol_node> >::iterator it;
											//it = symbol_table.symboltable.begin() + symbol_table.table_index;
											symbol_table.dump(symbol_table.table_index);
											//symbol_table.symboltable.erase(it);
											}
			| FUNCTION IDENTIFIER LP RP COLON type { symbol_table.create();
										vector<int> where;
										where = symbol_table.ALL_lookup($2);
										if(where.empty()){
											symbol_node temp;
											temp.name = $2;
											temp.content = "none";
											temp.type = $6;
											temp.Symbol_type = 0;
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
										} END IDENTIFIER	{
										//vector<vector<symbol_node> >::iterator it;
										//it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										//symbol_table.symboltable.erase(it);
										}*/
			;

procedure_declarations	: PROCEDURE IDENTIFIER LP formal_arguments RP { 
									symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);
									vector<int> where;
									where = symbol_table.ALL_lookup($2);
									if(where.empty()){
										symbol_node temp;
										temp.name = $2;
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										temp.argument_type = $4;
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
			| PROCEDURE IDENTIFIER LP RP { symbol_table.create();
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
			/*| PROCEDURE IDENTIFIER LP {symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);} formal_arguments RP 							{ 
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
									 END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
			| PROCEDURE IDENTIFIER	LP {symbol_table.create();} RP {
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
									END IDENTIFIER	{
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}*/
			;


formal_arguments	: args
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
						
const_declarations	: CONST IDENTIFIER COLON type ASSIGN {hasValue = true;} const_expression	{ 
											if(symbol_table.scope_lookup(symbol_table.table_index,$2)== 99999){
												if ($4 == $7.type){
													if($7.isNotVariable){
														symbol_node temp;
														temp.name = $2;
														temp.content = $7.content;
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
											hasValue = false;
											}
			| CONST IDENTIFIER ASSIGN {hasValue = true;} const_expression	{
									if(symbol_table.scope_lookup(symbol_table.table_index,$2) == 99999){
										if($5.isNotVariable){
											symbol_node temp;
											temp.name = $2;
											temp.content = $5.content;
											temp.type = $5.type;
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
									hasValue = false;
									}
			;
			
variable_declarations	: VAR IDENTIFIER ASSIGN {hasValue = true;} const_expression	{ 
									if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
										
										symbol_node temp;
										temp.name = $2;
										temp.content = $5.content;
										temp.type = $5.type;
										temp.Symbol_type = 3;
										symbol_table.insert(temp);
										int where = symbol_table.scope_lookup(symbol_table.table_index, $2);
										if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
											output << "field static ";
											switch(symbol_table.symboltable[symbol_table.table_index][where].type){
											case 0:
												output << "java.lang.String ";
												break;
											case 1:
												output << "int ";
												break;
											case 2: 
												output << "float ";
												break;
											case 3: //bool
												output << "int ";
												break;
											default:
												output << "ERROR ";
												break;
											}
											output << symbol_table.symboltable[symbol_table.table_index][where].name  << "=" << $5.content << endl;
										}
										else{
											output << "sipush " << $5.content << endl;
                                							output << "istore " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
										}
										
									}
									else{
										yyerror("this id is already exist(var)");
									}	
									hasValue = false;					
									}
			| VAR IDENTIFIER COLON type ASSIGN {hasValue = true;} const_expression	{
									if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
										if ($4 == $7.type){
											symbol_node temp;
											temp.name = $2;
											temp.content = $7.content;
											temp.type = $4;
											temp.Symbol_type = 3;
											symbol_table.insert(temp);
											int where = symbol_table.scope_lookup(symbol_table.table_index, $2);
											if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
												output << "field static ";
												switch(symbol_table.symboltable[symbol_table.table_index][where].type){
												case 0:
													output << "java.lang.String ";
													break;
												case 1:
													output << "int ";
													break;
												case 2: 
													output << "float ";
													break;
												case 3: // bool
													output << "int ";
													break;
												default:
													output << "ERROR ";
													break;
												}
												output << symbol_table.symboltable[symbol_table.table_index][where].name  << "=" << $7.content << endl;
											}
											else{
												output << "sipush " << $7.content << endl;
		                        							output << "istore " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
											}
										}
										else{	
											//cout << $4 << " " << $6.type;
											yyerror("VARIABLE TYPE ERROR");
										}
									}
									else{
										yyerror("this id is already exist(var)");
									}
									hasValue = false;
									}
			| VAR IDENTIFIER COLON type	{ 
							if(symbol_table.scope_lookup(symbol_table.table_index, $2) == 99999){
								symbol_node temp;
								temp.name = $2;
								temp.type = $4;
								temp.Symbol_type = 3;
								symbol_table.insert(temp);
								int where = symbol_table.scope_lookup(symbol_table.table_index, $2);
								if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									output << "field static ";
									switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									case 0:
										output << "java.lang.String ";
										break;
									case 1:
										output << "int ";
										break;
									case 2: 
										output << "float ";
										break;
									case 3: // bool 
										output << "int ";
										break;
									default:
										output << "ERROR ";
										break;
									}
									output << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								}
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
	/*| BYG {symbol_table.create();} variable_declarations END {
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
							}*/	
	| BYG /* empty */ END
	;
	
simple	: IDENTIFIER ASSIGN expressions	{
						int where = symbol_table.scope_lookup(symbol_table.table_index, $1);
						if(where == 99999)	{
							where = symbol_table.scope_lookup(0, $1);
							if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								output << "putstatic";
								switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2:
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								}
								cout << "this is global variable" << endl;
								output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							} 
						}
						else{
							cout << "this is local variable" << endl;
							output << "istore" << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
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
	| PUT { output << "getstatic java.io.PrintStream java.lang.System.out" << endl;} 
	  expressions {
	  	output << "invokevirtual void java.io.PrintStream.println(";
			switch($3.type){
		            case 0:
		                output << "java.lang.String ";
		                break;
		            case 1:
		                output << "int ";
		                break;
		            case 2: 
		                output << "float ";
		                break;
		            case 3: // bool
		                output << "int ";
		                break;
		            default:
		                output << "ERROR";
		                break;
		    }
                    output << ")" << endl;
                    }	
	| GET IDENTIFIER
	| RESULT expressions { output << "ireturn" << endl;}
	| RETURN { output << "return" << endl;}
	| EXIT WHEN boolean_expression
	| EXIT
	| SKIP { output << "getstatic java.io.PrintStream java.lang.System.out" <<endl;
		output << "invokevirtual void java.io.PrintStream.println()" << endl;}
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "iflt L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifle L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifeq L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifeq L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifge L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifgt L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifne L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifne L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
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
										if(!hasValue) {
											output << "ior" << endl;
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
										if(!hasValue) {
											output << "iand" << endl;
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
									cout << $1.type << " ... " << $3.type << endl;
									if($1.type == 1 && $3.type == 1){
										temp.type = 1;
										if($1.isNotVariable && $3.isNotVariable){
											temp.content = to_string(stoi($1.content) + stoi($3.content));
										}
										if(!hasValue){
											output << "iadd" << endl;
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
										if(!hasValue){
											output << "isub" << endl;
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
										if(!hasValue) {
											output << "imul" << endl;
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
										if(!hasValue){
											output << "idiv" << endl;
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
										if(!hasValue){
											output << "irem" << endl;
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
									if(!hasValue){
										output << "ineg" << endl;
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
                       							output << "invokestatic ";
										switch(symbol_table.symboltable[where[0]][where[1]].type){
											case 0:
											    output << "java.lang.String ";
											    break;
											case 1:
											    output << "int ";
											    break;
											case 2: 
											    output << "float ";
											    break;
											case 3: // bool
											    output << "int ";
											    break;
											default:
											    output << "ERROR ";
											    break;
										    }
										output << className << "." << symbol_table.symboltable[where[0]][where[1]].name;
										output << "(";
										vector<int> arg = symbol_table.symboltable[where[0]][where[1]].argument_type;
										
										for(int i=0;i<arg.size();i++){
										    switch(arg[i]){
											case 0:
											    output << "java.lang.String ";
											    break;
											case 1:
											    output << "int";
											    break;
											case 2: 
											    output << "float";
											    break;
											case 3: // bool
											    output << "int ";
											    break;
											default:
											    output << "ERROR";
											    break;
										    }
										    if(i!=arg.size() - 1){
											output<<", ";
										    }
										}
										output << ")" << endl;
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
				if(!hasValue){
					output << "ldc \"" << $1 << "\"" << endl;
				}            
				$$ = temp;
				}	
		| INTEGER	{
				expr_term temp;
				temp.type = 1;
				temp.isNotVariable = true;
				temp.content = to_string($1);
				if(!hasValue){
					output << "sipush " << $1 << endl;
				}
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
				string b;
				if(!hasValue){
					if($1){
						b = "1";
						output << "iconst_" << b << endl;
					}
					else{
						b = "0";
						output << "iconst_" << b << endl;
					}
				}
				$$ = temp;
				}
		| IDENTIFIER	{
				expr_term temp;
				int where = symbol_table.scope_lookup(symbol_table.table_index, $1);
				if(where == 99999){
					if(symbol_table.scope_lookup(0, $1) != 99999){
						where = symbol_table.scope_lookup(0, $1);
						temp.type = symbol_table.symboltable[0][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
						}
					}
				}
				else{
					temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
					if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
						temp.isNotVariable = false;
						if(!hasValue){
						    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
							    output << "getstatic ";
							    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
							    case 0:
								output << "java.lang.String ";
								break;
							    case 1:
								output << "int ";
								break;
							    case 2: 
								output << "float ";
								break;
							    case 3: // bool
								output << "int ";
								break;
							    default:
								output << "ERROR ";
								break;
							    }
						    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
						    }
						    else{
							output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
						    }
						}
					}
					else{
						temp.isNotVariable = true;
						temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
						if(temp.type == 1){
						   	if(!hasValue){
						    		output << "sipush " << temp.content << endl;
						   	}
						}
						else if(temp.type == 3){
						    	if(temp.content == "true"){
								if(!hasValue){
									output << "iconst_1" << endl;
								} 
						   	 }
							 else{
								if(!hasValue){
									output << "iconst_0" << endl;
								}
						   	 }
						}
						else if(temp.type == 0){
						 	if(!hasValue){
							    	output << "ldc \"" << temp.content << "\"" << endl;
						  	} 
						}
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

conditional	: IF boolean_expression THEN {symbol_table.create();output << "ifeq L" << label.If() << endl;} description 									{
								output << "goto Lexit" << label.If() << endl;
								output << "Lfalse" << label.If() << ":"<<endl; 
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);}
								ELSE {symbol_table.create();} 
								description END IF 
								{ 
								output << "Lexit" << label.If() << ":" <<endl;
                                                              label.If_add();
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								//cout << "number:::::: "<<symbol_table.table_index << endl;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
								}
		|IF boolean_expression THEN {symbol_table.create();output << "ifeq L" << label.If() << endl;} description {output << "goto Lexit" << label.If() << endl;}
												END IF {
												output << "Lexit" << label.If() << ":" <<endl;
                                                              				label.If_add();
												vector<vector<symbol_node> >::iterator it;
												it = symbol_table.symboltable.begin() + symbol_table.table_index;
												symbol_table.dump(symbol_table.table_index);
												symbol_table.symboltable.erase(it);
												}
		;
		
boolean_expression	: LP boolean_expression RP {$$ = $2;}
			| operand_expression LT operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "iflt L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression LET operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifle L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression EQ operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifeq L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifeq L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression GETH operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifge L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression GT operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifgt L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression NEQ operand_expression {
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifne L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifne L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
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
			| operand_expression OR operand_expression {
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
										if(!hasValue) {
											output << "ior" << endl;
										}
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									$$ =  temp;
									}
			| operand_expression AND operand_expression {
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
										if(!hasValue) {
											output << "iand" << endl;
										}
										
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									$$ =  temp;
									}
			| NOT operand_expression {
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
			| IDENTIFIER {
					expr_term temp;
					int where = symbol_table.scope_lookup(symbol_table.table_index, $1);
					if(where == 99999){
						if(symbol_table.scope_lookup(0, $1) != 99999){
							where = symbol_table.scope_lookup(0, $1);
							temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
							if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
								temp.isNotVariable = false;
								if(!hasValue){
								    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									    output << "getstatic ";
									    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									    case 0:
										output << "java.lang.String ";
										break;
									    case 1:
										output << "int ";
										break;
									    case 2: 
										output << "float ";
										break;
									    case 3: // bool
										output << "int ";
										break;
									    default:
										output << "ERROR ";
										break;
									    }
								    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								    }
								    else{
									output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
								    }
								}
							}
							else{
								temp.isNotVariable = true;
								temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
								if(temp.type == 1){
								   	if(!hasValue){
								    		output << "sipush " << temp.content << endl;
								   	}
								}
								else if(temp.type == 3){
								    	if(temp.content == "true"){
										if(!hasValue){
											output << "iconst_1" << endl;
										} 
								   	 }
									 else{
										if(!hasValue){
											output << "iconst_0" << endl;
										}
								   	 }
								}
								else if(temp.type == 0){
								 	if(!hasValue){
									    	output << "ldc \"" << temp.content << "\"" << endl;
								  	} 
								}
							}
						}
					}
					else{
						temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
						}
					}
					$$ = temp;
					}
			| BOOLEAN {
					expr_term temp;
					temp.type = 3;
					temp.isNotVariable = true;
					if($1 == true){
						temp.content = "true";
					}
					else{
						temp.content = "false";
					}
					if(!hasValue){
						output << "const_" << ($1 ? "1" : "0") << endl;
					}
					$$ = temp;
					}
			;

description	: %empty /* empty */
		| const_declarations description
		| variable_declarations description
		| statement_sequence description
		;

loop	:  LOOP {symbol_table.create(); output << "Lbegin" << label.Loop() << ":" << endl;} description
								END LOOP	{
								output << "goto Lbegin" << label.Loop() << ":" << endl;
								output << "Lexit" << label.Loop() << ":" << endl;
								label.Loop_add();
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
								}
	| FOR DECREASING IDENTIFIER COLON const_expression DOT DOT const_expression {
							if(atoi($5.content.c_str()) < atoi($8.content.c_str())){
								yyerror("For loop scope need to be decreasing sequence");
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
								symbol_table.create();
								output << "Lbegin" << label.Loop() << ":" << endl;
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
							} description END FOR	{
										output << "goto Lbegin" << label.Loop() << ":" << endl;
										output << "Lexit" << label.Loop() << ":" << endl;
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
	| FOR IDENTIFIER COLON const_expression DOT DOT const_expression{
							if($4.type == 1 && $7.type == 1){
								//cout << $5.content << " ............. " << $8.content;
								if(atoi($4.content.c_str()) < atoi($7.content.c_str())){
									//cout << $5.content << " ............. " << $8.content;
									symbol_table.create();
									output << "Lbegin" << label.Loop() << ":" << endl;
									symbol_node temp;
									temp.name = $2;
									temp.type = 1;
									temp.Symbol_type = 3;
									symbol_table.insert(temp);
								}
								else{
									yyerror("range cannot be decreasing");
								}
							}
							else{
								yyerror("range type must be integer");
							}
							} description END FOR {
										output << "goto Lbegin" << label.Loop() << ":" << endl;
										output << "Lexit" << label.Loop() << ":" << endl;
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
;

const_expression	: STRING 	{
					expr_term temp;
					temp.type = 0;
					temp.isNotVariable = true;
					temp.content = $1;
					if(!hasValue){
						output << "ldc \"" << $1 << "\"" << endl;
					} 
					$$ = temp;
					}
			| INTEGER	{
					expr_term temp;
					temp.type = 1;
					temp.isNotVariable = true;
					temp.content = to_string($1);
					if(!hasValue){
						output << "sipush " << $1 << endl;
					}
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
					string b;
					if(!hasValue){
						if($1){
							b = "1";
							output << "iconst_" << b << endl;
						}
						else{
							b = "0";
							output << "iconst_" << b << endl;
						}
					}
					$$ = temp;
					}
			| IDENTIFIER	{
					expr_term temp;
					int where = symbol_table.scope_lookup(symbol_table.table_index, $1);
					if(where == 99999){
						if(symbol_table.scope_lookup(0, $1) != 99999){
							where = symbol_table.scope_lookup(0, $1);
							temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
							if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
								temp.isNotVariable = false;
								if(!hasValue){
								    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									    output << "getstatic ";
									    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									    case 0:
										output << "java.lang.String ";
										break;
									    case 1:
										output << "int ";
										break;
									    case 2: 
										output << "float ";
										break;
									    case 3: // bool
										output << "int ";
										break;
									    default:
										output << "ERROR ";
										break;
									    }
								    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								    }
								    else{
									output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
								    }
								}
							}
							else{
								temp.isNotVariable = true;
								temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
								if(temp.type == 1){
								   	if(!hasValue){
								    		output << "sipush " << temp.content << endl;
								   	}
								}
								else if(temp.type == 3){
								    	if(temp.content == "true"){
										if(!hasValue){
											output << "iconst_1" << endl;
										} 
								   	 }
									 else{
										if(!hasValue){
											output << "iconst_0" << endl;
										}
								   	 }
								}
								else if(temp.type == 0){
								 	if(!hasValue){
									    	output << "ldc \"" << temp.content << "\"" << endl;
								  	} 
								}
							}
						}
					}
					else{
						temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
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
    //exit(0);
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
		if(argc>1){
			output.open(argv[1], ios::out | ios::trunc);
        	}
        	else{
            		output.open("output.jasm", ios::out | ios::trunc);
        	}
	}
	//--- Stdin ---//
	else{
		//cout << "!!!!!!!fsdgragre" << endl;
	}
    	yyparse();
  
    	if ( argc > 0 ){
        	fclose(input);
    	}
    	output.close();
	return 0;
}
