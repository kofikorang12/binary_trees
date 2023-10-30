#include "binary_trees.h"

/**
 * binary_tree_sibling - finds a node sibling
 * @node: node to be evaluated
 *
 * Return: the sibling node/Null on failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->n < node->parent->n)
	{
		return (node->parent->right);
	}

	return (node->parent->left);
}

/**
 * binary_tree_uncle - finds a node's uncle
 * @node: node to be evaluated
 *
 * Return: the uncle node / NULL on failure
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}
