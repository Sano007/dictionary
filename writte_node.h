#ifndef IO_NODE_H
#define IO_NODE_H

#include "dictionary.h"


struct Dict* add_node(struct Dict* self, char* word);


struct Dict* find_node(struct Dict* self, char* word);


struct Dict* remove_node(struct Dict* self, char name);


#endif