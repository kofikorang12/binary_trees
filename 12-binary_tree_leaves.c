#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves on a tree
 * @tree: tree to be evaluated
 *
 * Return: number of nodes without two children, 0 on failure
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	if (left == 0 && right == 0)
	{
		return (1);
	}

	return (left + right);
}
