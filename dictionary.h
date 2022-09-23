#ifndef DICT_H
#define DICT_H

#include <stdbool.h>


struct Node{
	char name;
	unsigned int nb_children;
	struct Node** children;
	bool is_word;
	char* last_word;
};


struct Dict{
	struct Node child;
	u_int64_t words_count;
};


struct Dict* create_dictionary();


void add_word(struct Dict* dictionary, char* word);


void remove_word(struct Dict* dictionary, char* word);


char** list_all(struct Dict* dictionary);


bool is_in_dict(struct Dict* dictionary, char* word);


#endif