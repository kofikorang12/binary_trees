#include "binary_trees.h"

/**
 * check_min_max - chekcs if a node is within a valid range
 * @node: node to be evaluated
 * @min: minimum of valid range
 * @max: maximum of valid range
 *
 * Return: 1 if node and all nodes below are in respective ranges
 */
int check_minimax(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
	{
		return (1);
	}

	if (node->left != NULL &&
	    (node->left->n <= min ||
	    node->left->n >= node->n))
	{
		return (0);
	}

	if (node->right != NULL &&
	    (node->right->n <= node->n ||
	    node->right->n >= max))
	{
		return (0);
	}

	if (check_minimax(node->left, min, node->n) == 0)
	{
		return (0);
	}

	if (check_minimax(node->right, node->n, max) == 0)
	{
		return (0);
	}

	return (1);
}

/**
 * binary_tree_is_bst - checks if a tree is a binary search tree
 * @tree: tree to be checked
 *
 * Return: 1 if bst 0 if not/failure
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (check_minimax(tree, INT_MIN, INT_MAX) == 1)
	{
		return (1);
	}

	return (0);
}
