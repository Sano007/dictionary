#ifndef DICT_H
#define DICT_H


struct Dict{
	char name;
	unsigned int childs;
	char* children;
	bool is_word;
	char* last_word;
};


struct Dict create_dictionary();


struct Dict add_word(char* word);


struct Dict remove_word(char* word);


char** list_all();


bool is_in_dict(char* word);


#endif