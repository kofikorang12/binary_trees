#include "binary_trees.h"

/**
 * traverse_rows_height - counts rows of tree
 * @tree: tree to be evaluated
 *
 * Return: rows, or 0 on failure
 */
int traverse_rows_height(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (0);
	}

	left = traverse_rows_height(tree->left);
	right = traverse_rows_height(tree->right);

	if (left > right)
	{
		return (left + 1);
	}

	return (right + 1);
}

/**
 * check_min_max - checks if a node is within a valid range
 * @node: node to be evaluated
 * @min: minimum of valid range
 * @max: maximum of valid range
 *
 * Return: 1 if node and all nodes below are in respective ranges
 */
int check_min_max(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
	{
		return (1);
	}

	if (node->left != NULL &&
	    (node->left->n < min ||
	    node->left->n >= node->n))
	{
		return (0);
	}

	if (node->right != NULL &&
	    (node->right->n < node->n ||
	    node->right->n >= max))
	{
		return (0);
	}

	if (check_min_max(node->left, min, node->n) == 0)
	{
		return (0);
	}

	if (check_min_max(node->right, node->n, max) == 0)
	{
		return (0);
	}

	return (1);
}

/**
 * compare_heights - compares heights of 2 brances
 * @tree: tree to be evaluated
 *
 * Return: 1 if heights are within 1 level, 0 if not
 */
int compare_heights(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (1);
	}

	left = traverse_rows_height(tree->left);
	right = traverse_rows_height(tree->right);

	if (left < right - 1 || left > right + 1)
	{
		return (0);
	}

	if (compare_heights(tree->left) == 0)
	{
		return (0);
	}

	if (compare_heights(tree->right) == 0)
	{
		return (0);
	}

	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is AVL (self balancing)
 * @tree: tree to be evaluated
 *
 * Return: 1 if AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (check_min_max(tree, INT_MIN, INT_MAX) == 0)
	{
		return (0);
	}

	return (compare_heights(tree));
}
