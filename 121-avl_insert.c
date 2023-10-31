#include "binary_trees.h"

/**
 * bst_insert - inserts of node into a binary search tree
 * @tree: tree to be operated on
 * @value: value to be inserted
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

/**
 * balance_up - after shifting nodes, balances root
 * nodes farther up tree
 * @iter: current root being balanced
 *
 * Return: root of tree
 */
avl_t *balance_up(avl_t *iter)
{
	int balance_factor;
	avl_t *tree;

	while (iter != NULL)
	{
		balance_factor = binary_tree_balance(iter);

		if (balance_factor > 1)
		{
			if (binary_tree_balance(iter->left) < 0)
			{
				binary_tree_rotate_left(iter->left);
			}

			iter = binary_tree_rotate_right(iter);
			iter = iter->left;
		}
		else if (balance_factor < -1)
		{
			if (binary_tree_balance(iter->right) > 0)
			{
				binary_tree_rotate_right(iter->right);
			}

			iter = binary_tree_rotate_left(iter);
			iter = iter->right;
		}
		else
		{
			tree = iter;
			iter = iter->parent;
		}
	}

	return (tree);
}

/**
 * avl_insert - inserts a node into an avl tree
 * @tree: root of tree
 * @value: value to be inserted
 *
 * Return: new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		return (NULL);
	}

	new_node = bst_insert(tree, value);

	*tree =  balance_up(new_node);

	return (new_node);
}
