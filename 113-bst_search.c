#include "binary_trees.h"

/**
 * bst_search - finds a value in a binary search tree
 * @tree: tree to be searched
 * @value: value of node to find
 *
 * Return: node if found NULL if not/failure
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value == tree->n)
		{
			return ((bst_t *)tree);
		}

		if (value < tree->n)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}

	return (NULL);
}
