#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

struct array_range{
	string array_name;
	int start;
	int end;
	int volume;	
};

struct expr_term{
	string content;
	int type; // string = 0, int = 1, float = 2, bool = 3
	bool isNotVariable;
};

struct Type{
	string variable;
	int int_val;
	float float_val;
	bool bool_val;
	string str_val;
	expr_term expr_result;
	int typical_type; // string = 0, int = 1, real(float) = 2, bool = 3
	vector<int> argument_list;
};

struct symbol_node{	
	string name;
	string content;
	int type; // none = -1, string = 0, int = 1, float = 2, bool = 3
	int Symbol_type; // function = 0, procedure = 1, const = 2, variable = 3, array = 4
	vector<int> argument_type;
	bool isGlobal;
	int var_index;
};

class Symbol_Table{
	public:
	int table_index = -1;
	vector<vector<symbol_node> > symboltable;
	vector<int> argument_place;
	int var_count = -1;
	
	void create() {
		vector<symbol_node> this_table;
		this->symboltable.push_back(this_table);
		this->table_index++;
		cout << "This is No." << this->table_index << " Symbol Table." << endl;
	}

	int scope_lookup(int scope, string id){
		for(int i = 0;i < this->symboltable[this->table_index].size();i++){
			if(id == this->symboltable[scope][i].name){
				return i; // found it
			}
		}
		return 99999; // didn't find
	}
	
	vector<int> ALL_lookup(string id){
		vector<int> place;
		/*for(int i = 0;i < this->symboltable.size();i++){
			cout << "No." << i << "Symbol Table:";
			for(int j = 0;j < this->symboltable[i].size();j++){
				cout << this->symboltable[i][j].name << " ";
			}
			cout << endl;
		}*/
		//cout << id << endl;
		for(int i = 0;i < this->symboltable.size();i++){
			for(int j = 0;j < this->symboltable[i].size();j++){
				if(id == this->symboltable[i][j].name){
					//cout << "this symbol table [i][j]: " << this->symboltable[i][j].name << endl;
					place.push_back(i);
					place.push_back(j);
					return place; // fount it;
				}
			}
		}
		return place; // didn't find
	}
	void insert(symbol_node symbol){
		if(scope_lookup(table_index , symbol.name) != 99999){
			cout << symbol.name <<" is already in the symbol table" << endl;
			//this->symboltable[this->table_index].push_back(symbol);
		}
		else{
			if(symbol.Symbol_type == 0 || symbol.Symbol_type == 1) {
				cout << "push " << symbol.name << " in Symbol Table" << endl;
				this->symboltable[0].push_back(symbol);
			}
			else{
				if(symbol.Symbol_type == 3){
					if(this->table_index == 0){
						symbol.var_index = -1;
						symbol.isGlobal = true;
					}
					else{
						symbol.isGlobal = false;
						symbol.var_index = this->var_count;
						this->var_count++;
					}
				}
				cout << "push " << symbol.name << " in Symbol Table" << endl;
				this->symboltable[this->table_index].push_back(symbol);
			}
			
		}
	}

	void dump(int index){
		cout << "The content of the symbol table in No. " << index << endl;
		for (int i = 0;i < symboltable[index].size();i++){
			cout << symboltable[index][i].name << "\t" << symboltable[index][i].content << "\t" << symboltable[index][i].type << "\t" << symboltable[index][i].Symbol_type << endl;
		}
		int check = 0;
		for(int i = 0;i < argument_place.size();i++){
			if(index == argument_place[i]){
				check++;
			}
		}
		if(check > 0){
		
		}
		else{
			table_index--;
		}
	}

};
class Label{
    public:
    int label_if = 0;
    int label_loop = 0;
    int label_boolexpr = -1;
    int If(){
        return label_if;
    }
    void If_add(){
        label_if++;
    }
    int Loop(){
        return label_loop;
    }
    void Loop_add(){
        label_loop++;
    }
    int Boolexpr(){
        label_boolexpr++;
        return label_boolexpr;
    }
};
extern Symbol_Table symbol_table;
extern int linenum;
#define YYSTYPE Type
#endif
