#include "binary_trees.h"

/**
 * bst_insert - inserts of node into a binary search tree
 * @tree: tree to be operated on
 * @value: value to be inserted to
 *
 * Return: root or tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = *tree;
	bst_t *child = *tree;

	if (tree == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	while (child != NULL)
	{
		parent = child;

		if (value < parent->n)
		{
			child = parent->left;
		}
		else if (value > parent->n)
		{
			child = parent->right;
		}
		else
		{
			return (NULL);
		}
	}

	child = binary_tree_node(parent, value);

	if (value < parent->n)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	return (child);
}
