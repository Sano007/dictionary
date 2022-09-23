#ifndef DICT_H
#define DICT_H

//#include "read_node.h"
#include "writte_node.h"


struct Dict{
	char name;
	unsigned int childs;
	char* children;
	bool is_word;
	char* last_word;
};


struct Dict create_dictionary();


struct Dict add_word(struct Dict* dictionary, char* word);


struct Dict remove_word(struct Dict* dictionary, char* word);


char** list_all(struct Dict* dictionary);


bool is_in_dict(struct Dict* dictionary, char* word);


#endif