#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "writte_node.h"


struct Dict *new_node(char *word)
{
	struct Dict *new = calloc(1, sizeof(struct Dict));
	new->children = NULL;
	new->nb_children = 0;
	new->is_word = true;
	new->name = word[0];
	new->last_word = strlen(word) > 1 ? &word[1] : NULL;
	return new;
}


struct Dict *add_node(struct Dict *self, char *word)
{
	if (self == NULL)
		return NULL;
	if (word == NULL || word[0] == '\0')
		return NULL;
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
		struct Dict **new_children = calloc(self->nb_children, sizeof(struct Dict *));
		memcpy(new_children, self->children, self->nb_children);
		free(self->children);
		new_children[self->nb_children - 1] = new_node(&word[1]);
	}
	else
	{
		if (self->last_word == NULL)
		{
			self->nb_children++;
			self->children = calloc(1, sizeof(struct Dict *));
			self->children[0] = new_node(&word[1]);
		}
		else
		{
			self->nb_children = 2;
			self->children = calloc(2, sizeof(struct Dict *));
			self->children[1] = new_node(&word[1]);
			self->children[0] = new_node(self->last_word);
			self->is_word = false;
			self->last_word = NULL;
		}
	}
	return self;
}