#include "binary_trees.h"

/**
 * find_lnode - finds last node in tree
 * @root: root of current subtree
 * @height: used to determine if we are on the last level of tree
 *
 * Return: last node
 */
heap_t *find_lnode(heap_t *root, size_t height)
{
	heap_t *left;
	heap_t *right;

	if (root == NULL)
	{
		return (NULL);
	}

	if (height == 0 && binary_tree_height(root) == height)
	{
		return (root);
	}

	right = find_lnode(root->right, height - 1);
	if (right != NULL)
	{
		return (right);
	}

	left = find_lnode(root->left, height - 1);
	if (left != NULL)
	{
		return (left);
	}

	return (NULL);
}

/**
 * replace - replaces one node with another
 * @to_delete: node to be deleted
 * @to_replace: node to replace deleted with (or NULL)
 */
void replace(bst_t *to_delete, bst_t *to_replace)
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

		to_replace->parent = to_delete->parent;
		to_replace->left = to_delete->left;
		to_replace->right = to_delete->right;
	}

	if (to_delete->parent != NULL)
	{
		if (to_delete->parent->left == to_delete)
		{
			to_delete->parent->left = to_replace;
		}
		else
		{
			to_delete->parent->right = to_replace;
		}
	}

	if (to_delete->left != NULL)
	{
		to_delete->left->parent = to_replace;
	}
	if (to_delete->right != NULL)
	{
		to_delete->right->parent = to_replace;
	}

	free(to_delete);
}

heap_t *switch_up(heap_t *node);

/**
 * heap_extract - extracts root of tree
 * @root: root of tree
 *
 * Return: value of old root
 */
int heap_extract(heap_t **root)
{
	heap_t *parent;
	heap_t *child;
	heap_t *last_node;
	size_t height = binary_tree_height(*root);
	int extract_val;

	if (root == NULL || *root == NULL)
	{
		return (0);
	}

	child = *root;

	extract_val = child->n;

	while (child != NULL)
	{
		parent = child;
		if (parent->left != NULL)
		{
			if (parent->right != NULL && parent->left->n < parent->right->n)
			{
				parent->n = parent->right->n;
				child = parent->right;
			}
			else
			{
				parent->n = parent->left->n;
				child = parent->left;
			}
		}
		else 
		{
			child = NULL;
		}
	}

	last_node = find_lnode(*root, height);

	if (last_node == *root)
	{
		free (*root);
		*root = NULL;
		return (extract_val);
	}

	if (last_node == parent)
	{
		replace(parent, NULL);
		return (extract_val);
	}

	replace(parent, last_node);

	switch_up(last_node);

	return (extract_val);
}
