#define _My_Parser_
#include "SymbolTable.h"
#include <string>
#include <set>
#include<vector>
#include "C:\\Users\\CEC\\Desktop\\CompilerProject-master\\CompilerProject-master\\CSTokens\\ErrorRecovery.h"

class MyParser {
public:
	SymbolTable* Symbol_Table;
	ErrorRecovery Error_Recovery;
	char* filename;
	MyParser();
	Class* create_class(char*, bool, InheritanceList*, Access_Modifier*, Data_Storage*, int, int);//add colNo & LineNo
	Class* start_class_declaration(Class*);
	Class* finish_class_declaration(Class*);
	Data_Member* name_am_ds_val_of_data_member(char*, Access_Modifier*, Data_Storage*);
	Function* create_function(char*, List_Parameters*, Access_Modifier*, Data_Storage*, bool, int, int);//add colNo & LineNo
	Function* start_function_declaration(Function*);
	Function* finish_function_declaration(Function*);
	Block_Scope* create_scope(int); 
	Local_Variable* create_local_variable(char*, int, int);//add colNo & LineNo
	Data_Member* create_data_member(char*, Access_Modifier*, Data_Storage*, int, int);//add colNo & LineNo
	Access_Modifier* set_access_modifier(int, int, int);
	Data_Storage* set_data_storage(int, int, int);//add colNo & LineNo
	List_Parameters* add_parameters(char*, bool, List_Parameters*,char*);//add colNo & LineNo
	Block_Scope* start_scope_declaration(Block_Scope*, int);
	Block_Scope* finish_scope_declaration(Block_Scope*, int);
	void print(SymbolTable*);
	void sprint(MyMap*);
	void addError(int, int, char*, char*);
	InheritanceList* add_class_list(char*, InheritanceList*);
	void set_Inheritance_pointers(MyMap*);
	Class* find_Inheritance_class_by_name(Block_Scope*, string, bool);
	Class* find_inner_classes_inheritence_in_scope(Block_Scope*, string);

	void check_all(SymbolTable*);
	int check_main_function(MyMap*);
	void check_main_Class(MyMap*);
	void check_function_overload_in_all_classes(MyMap*);
	void check_function_overload_in_class(MyMap*);
	void check_class_names_not_used_multiple_times(MyMap*);
	void check_function_parameters_names(MyMap*);
	void check_variables_and_datamembers_names(MyMap*);
	void check_inheritance_loop(MyMap*);
	void check_all_classes_names_over_parents(MyMap*, vector<string>);
	bool dfs_for_check_inheritance(Class*);
	void check_function_parameters_virtual(MyMap*);
	void check_allFunction_overrided_fromInterface(MyMap*);
	bool check_class_functions_override_allInterface_functions(vector<Function*>, Class*);
	void start(vector<MyParser*>sy_main);
	bool checked_file_class(MyMap* map, char*);
	void check_all_function_for_overriding(MyMap*);
	int check_override_from_final_function(Class*, Function*);
	void check_interfaces_functions_not_final_and_static(MyMap*);
	void check_all_interfaces_functions_not_final_and_static(MyMap*);
	void  check_interface_functions_not_final_or_static(MyMap*);
private:
	set<Class*> checked_classes_gray;
	set<Class*>	checked_classes_black;
};