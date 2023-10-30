#include "binary_trees.h"

/**
 * traverse_height - counts height of tree
 * @tree: tree to be evaluated
 *
 * Return: rows, or 0 on failure
 */
int traverse_height(const binary_tree_t *tree)
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
 * binary_tree_balance - finds balance factor of tree
 * @tree: tree to be evaluated
 *
 * Return: balance factor, 0 on failure
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (0);
	}

	left = traverse_height(tree->left);
	right = traverse_height(tree->right);

	return (left - right);
}
