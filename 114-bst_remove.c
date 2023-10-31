#include "binary_trees.h"

/**
 * bst_search - finds a value in a binary search tree
 * @tree: tree to be searched
 * @value: value of node to find
 *
 * Return: node if found NULL if not orfailure
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

/**
 * replace - replaces one node with another
 * @to_dele: node to be deleted
 * @to_replace: node to replace deleted with (or NULL)
 */
void replace(bst_t *to_dele, bst_t *to_replace)
{
	if (to_replace != NULL)
	{
		if (to_replace->parent->left == to_replace)
		{
			if (to_replace->left != NULL)
			{
				to_replace->parent->left = to_replace->left;
				to_replace->left->parent = to_replace->parent;
			}
			else if (to_replace->right != NULL)
			{
				to_replace->parent->left = to_replace->right;
				to_replace->right->parent = to_replace->parent;
			}
			else
			{
				to_replace->parent->left = NULL;
			}
		}
		else
		{
			if (to_replace->left != NULL)
			{
				to_replace->parent->right = to_replace->left;
				to_replace->left->parent = to_replace->parent;
			}
			else if (to_replace->right != NULL)
			{
				to_replace->parent->right = to_replace->right;
				to_replace->right->parent = to_replace->parent;
			}
			else
			{
				to_replace->parent->right = NULL;
			}
		}

		to_replace->parent = to_dele->parent;
		to_replace->left = to_dele->left;
		to_replace->right = to_dele->right;
	}

	if (to_dele->parent != NULL)
	{
		if (to_dele->parent->left == to_dele)
		{
			to_dele->parent->left = to_replace;
		}
		else
		{
			to_dele->parent->right = to_replace;
		}
	}

	if (to_dele->left != NULL)
	{
		to_dele->left->parent = to_replace;
	}
	if (to_dele->right != NULL)
	{
		to_dele->right->parent = to_replace;
	}

	free(to_dele);
}

/**
 * bst_remove - removes a node from a binary search tree
 * @root: root of tree
 * @value: value of node to be removed
 *
 * Return: root of tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_dele;
	bst_t *to_replace;

	if (root == NULL)
	{
		return (NULL);
	}

	to_dele = bst_search(root, value);
	if (to_dele == NULL)
	{
		return (root);
	}

	if (to_dele->right != NULL)
	{
		to_replace = to_dele->right;

		while (to_replace->left != NULL)
		{
			to_replace = to_replace->left;
		}
	}
	else if (to_dele->left != NULL)
	{
		to_replace = to_dele->left;

		while (to_replace->right != NULL)
		{
			to_replace = to_replace->right;
		}
	}
	else
	{
		to_replace = NULL;
	}

	if (to_dele == root)
	{
		root = to_replace;
	}

	replace(to_dele, to_replace);
	return (root);
}
