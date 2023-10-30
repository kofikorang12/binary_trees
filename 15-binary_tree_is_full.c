#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if all nodes
 * @tree: tree to be evaluated
 *
 * Return: 1 if full, 0 if not/failure
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->right == NULL)
	{
		if (tree->left == NULL)
		{
			return (1);
		}

		return (0);
	}
	if (tree->left == NULL)
	{
		return (0);
	}

	if (binary_tree_is_full(tree->left) == 1 &&
	    binary_tree_is_full(tree->right) == 1)
	{
		return (1);
	}

	return (0);
}
