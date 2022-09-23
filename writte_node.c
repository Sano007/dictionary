#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "writte_node.h"


struct Node *new_node(char *word){
	struct Node *new = calloc(1, sizeof(struct Node));
	new->children = NULL;
	new->nb_children = 0;
	new->is_word = true;
	new->name = word[0];
	new->last_word = strlen(word) > 1 ? &word[1] : NULL;
	return new;
}


int compare(const void *a, const void *b){
	struct Node* a1 = (struct Node*)(a);
	struct Node* b1 = (struct Node*)(b);
	return a1->name - b1->name;
}


struct Node* add_node(struct Node* self, char *word){
	if (word == NULL)
		return NULL;
	if(word[0] == '\0') return NULL;
	if (self == NULL)
		return new_node(word);
	if (self->nb_children > 0)
	{
		for (int i = 0; i < self->nb_children; i++)
		{
			if (self->children[i]->name == word[0])
			{
				self->children[i] = add_node(self->children[i], &word[1]);
				return self;
			}
		}
		self->nb_children++;
		struct Node** new_children = calloc(self->nb_children, sizeof(struct Node*));
		memcpy(new_children, self->children, self->nb_children);
		free(self->children);
		new_children[self->nb_children - 1] = new_node(&word[1]);
		qsort(new_children, self->nb_children, sizeof(struct Node*), compare);
	}
	else
	{
		if (self->last_word == NULL)
		{
			self->nb_children++;
			self->children = calloc(1, sizeof(struct Node*));
			self->children[0] = new_node(&word[1]);
		}
		else
		{
			self->nb_children = 2;
			self->children = calloc(2, sizeof(struct Node*));
			self->children[1] = new_node(&word[1]);
			self->children[0] = new_node(self->last_word);
			self->is_word = false;
			self->last_word = NULL;
			qsort(self->children, self->nb_children, sizeof(struct Node*), compare);
		}
	}
	return self;
}


struct Node* remove_node(struct Node* self, char name){
	if(self == NULL) return NULL;
	if(name == '\0') return NULL;
	if(self->children != NULL) return NULL;
	free(self->last_word);
	free(self->children);
	free(self);
	return NULL;
}

