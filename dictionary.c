#include <stdlib.h>
#include "dictionary.h"
#include "writte_node.h"


struct Dict* create_dictionary(){
	struct Dict* new_dictionary = calloc(1, sizeof(struct Dict));
	new_dictionary->words_count = 0;
	new_dictionary->child.name = '\0';
	new_dictionary->child.is_word = false;
	new_dictionary->child.children = NULL;
	new_dictionary->child.nb_children = 0;
	new_dictionary->child.last_word = NULL;
	return new_dictionary;
}


void add_word(struct Dict* dictionary, char* word){
	return;
}