#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: root of tree/subtree to be rotated
 *
 * Return: new root of tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_ro;

	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}

	new_ro = tree->left;
	tree->left = new_ro->right;

	if (tree->left != NULL)
	{
		tree->left->parent = tree;
	}

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = new_ro;
		}
		else
		{
			tree->parent->right = new_ro;
		}
	}

	new_ro->parent = tree->parent;
	new_ro->right = tree;
	tree->parent = new_ro;

	return (new_ro);
}
