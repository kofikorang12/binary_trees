#include "binary_trees.h"

/**
 * bst_search - finds a value in a binary trees
 * @tree: tree to be searched
 * @value: value of node to find
 *
 * Return: node if found, NULL if not/failure
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
 * @to_del: node to be deleted
 * @to_rep: node to replace deleted with (or NULL)
 */
void replace(bst_t *to_del, bst_t *to_rep)
{
	if (to_rep != NULL)
	{
		if (to_rep->parent->left == to_rep)
		{
			if (to_rep->left != NULL)
			{
				to_rep->parent->left = to_rep->left;
				to_rep->left->parent = to_rep->parent;
			}
			else if (to_rep->right != NULL)
			{
				to_rep->parent->left = to_rep->right;
				to_rep->right->parent = to_rep->parent;
			}
			else
			{
				to_rep->parent->left = NULL;
			}
		}
		else
		{
			if (to_rep->left != NULL)
			{
				to_rep->parent->right = to_rep->left;
				to_rep->left->parent = to_rep->parent;
			}
			else if (to_rep->right != NULL)
			{
				to_rep->parent->right = to_rep->right;
				to_rep->right->parent = to_rep->parent;
			}
			else
			{
				to_rep->parent->right = NULL;
			}
		}

		to_rep->parent = to_del->parent;
		to_rep->left = to_del->left;
		to_rep->right = to_del->right;
	}

	if (to_del->parent != NULL)
	{
		if (to_del->parent->left == to_del)
		{
			to_del->parent->left = to_rep;
		}
		else
		{
			to_del->parent->right = to_rep;
		}
	}

	if (to_del->left != NULL)
	{
		to_del->left->parent = to_rep;
	}
	if (to_del->right != NULL)
	{
		to_del->right->parent = to_rep;
	}

	free(to_del);
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
	bst_t *to_del;
	bst_t *to_rep;

	if (root == NULL)
	{
		return (NULL);
	}

	to_del = bst_search(root, value);
	if (to_del == NULL)
	{
		return (root);
	}

	if (to_del->right != NULL)
	{
		to_rep = to_del->right;
	}
	else if (to_del->left != NULL)
	{
		to_rep = to_del->left;
	}
	else
	{
		replace(to_del, NULL);
		return (NULL);
	}

	while (TRUE)
	{
		if (to_rep->left != NULL)
		{
			to_rep = to_rep->left;
		}
		else if (to_rep->right != NULL)
		{
			to_rep = to_rep->right;
		}
		else
		{
			break;
		}
	}

	if (to_del == root)
	{
		root = to_rep;
	}

	replace(to_del, to_rep);
	return (root);
}

avl_t *balance_up(avl_t *iter);

/**
 * avl_remove - removes a node from an avl tree
 * @root: root of tree
 * @value: value of node to be removed
 *
 * Return: root of tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *to_del;
	avl_t *parent_of_deleted;

	if (root == NULL)
	{
		return (NULL);
	}

	to_del = bst_search(root, value);
	if (to_del == NULL)
	{
		return (root);
	}
	parent_of_deleted = to_del->parent;

	if (parent_of_deleted == NULL)
	{
		parent_of_deleted = bst_remove(root, value);
	}
	else
	{
		bst_remove(root, value);
	}

	return (balance_up(parent_of_deleted));
}
