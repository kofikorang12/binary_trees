#include "binary_trees.h"

/**
 * binary_depth - finds depth of a node
 * @node: node to be evaluated
 *
 * Return: depth of node/0 on failure
 */
size_t binary_depth(const binary_tree_t *node)
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

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes
 * @first: one node
 * @second: another node
 *
 * Return: ancestor node, NULL on failure
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t f_depth;
	size_t s_depth;
	size_t i;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	f_depth = binary_depth(first);
	s_depth = binary_depth(second);

	if (f_depth > s_depth)
	{
		for (i = 0; i < f_depth - s_depth; i++)
		{
			first = first->parent;
			if (first == NULL)
			{
				return (NULL);
			}
		}
	}
	if (s_depth > f_depth)
	{
		for (i = 0; i < s_depth - f_depth; i++)
		{
			second = second->parent;
			if (second == NULL)
			{
				return (NULL);
			}
		}
	}

	while (first != NULL && second != NULL)
	{
		if (first == second)
		{
			return ((binary_tree_t *)first);
		}

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
