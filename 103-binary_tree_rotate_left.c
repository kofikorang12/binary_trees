#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: root of tree/subtree to be rotated
 *
 * Return: new root of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
	{
		return (tree);
	}

	new_root = tree->right;
	tree->right = new_root->left;

	if (tree->right != NULL)
	{
		tree->right->parent = tree;
	}

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = new_root;
		}
		else
		{
			tree->parent->right = new_root;
		}
	}

	new_root->parent = tree->parent;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
