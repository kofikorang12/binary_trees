#include "binary_trees.h"

/**
 * binary_tree_node - creates a node for a binary tree
 * @parent: parent of node
 * @value: value of node
 *
 * Return: pointer to new node NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_n->n = value;
	new_n->left = NULL;
	new_n->right = NULL;
	new_n->parent = parent;

	return (new_n);
}
