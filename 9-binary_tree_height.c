#include "binary_trees.h"

/**
 * traverse_height - counts rows of tree
 * @tree: tree to be evaluated
 *
 * Return: rows, or 0 on failure
 */
int traverse_rows(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (0);
	}

	left = traverse_height(tree->left);
	right = traverse_height(tree->right);

	if (left > right)
	{
		return (left + 1);
	}

	return (right + 1);
}

/**
 * binary_tree_height - finds height of binary tree
 * @tree: tree to be evaluated
 *
 * Return: height of tree, or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int rows = traverse_height(tree);

	if (rows == 0)
	{
		return (0);
	}

	return (rows - 1);
}
