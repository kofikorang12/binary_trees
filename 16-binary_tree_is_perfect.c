#include "binary_trees.h"

/**
 * compare_branch - checks if brances of a root are equal
 * @tree: tree/subtree to be checked
 *
 * Return: length of nodes, or 0 if failure
 */
int compare_branch(const binary_tree_t *tree)
{
	int left;
	int right;

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

	left = compare_branch(tree->left);
	right = compare_branch(tree->right);

	if (left == right)
	{
		return (left + 1);
	}

	return (0);
}

/**
 * binary_tree_is_perfect - checks if all levels are full
 * @tree: tree to be checked
 *
 * Return: 1 if perfect, 0 if not/failure
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (compare_branch(tree) == 0)
	{
		return (0);
	}

	return (1);
}
