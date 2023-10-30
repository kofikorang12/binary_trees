#include "binary_trees.h"

/**
 * binary_tree_depth - finds depth of a node
 * @node: node to be evaluated
 *
 * Return: depth of node, or 0 on failure
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	int i;

	if (node == NULL)
	{
		return (0);
	}

	for (i = 0; node != NULL; i++, node = node->parent)
		;

	return (i - 1);
}
