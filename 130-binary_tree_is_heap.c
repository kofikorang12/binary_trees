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
 * check_for_leaves - checks that all leaves are on the right
 * of the lowest level
 * @tree: tree to be evaluated
 * @depth: depth node should be at
 * @height: height of tree
 * @no_more_child: boolean keeps track if there should be
 * no more leaves in last level
 *
 * Return: TRUE if tree may be complete, false if not
 */
int check_for_leaves(const binary_tree_t *tree, size_t depth,
		     size_t height, int *no_more_child)
{
	if (tree->left == NULL)
	{
		if (tree->right == NULL)
		{
			if (depth == height && *no_more_child == FALSE)
			{
				return (TRUE);
			}
			if (depth == height - 1)
			{
				if (*no_more_child == FALSE)
				{
					*no_more_child = TRUE;
				}
				return (TRUE);
			}

			return (FALSE);
		}

		return (FALSE);
	}
	if (tree->right == NULL)
	{
		if (depth == height - 1 && *no_more_child == FALSE)
		{
			*no_more_child = TRUE;
			return (TRUE);
		}

		return (FALSE);
	}

	if (check_for_leaves(tree->left, depth + 1, height, no_more_child) == TRUE &&
	    check_for_leaves(tree->right, depth + 1, height, no_more_child) == TRUE)
	{
		return (TRUE);
	}

	return (FALSE);
}

/**
 * binary_tree_is_complete - checks if level except last are filled
 * and last level's nodes are as far left as possible
 * @tree: tree to be evaluated
 *
 * Return: 1 if complete, 0 if not/failure
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height;
	int no_more_child = FALSE;
	int rows = traverse_rows_height(tree);

	if (rows == 0)
	{
		height = 0;
	}
	else
	{
		height = rows - 1;
	}

	if (tree == NULL)
	{
		return (0);
	}

	if (height == 0)
	{
		return (1);
	}

	return (check_for_leaves(tree, 0, height, &no_more_child));
}


/**
 * check_max - checks if all child nodes are less than their parent nodes
 * @tree: tree to be evaluated
 *
 * Return: 1 if all max, 0 if not
 */
int check_max(const binary_tree_t *tree)
{
	if (tree->right != NULL && tree->right->n > tree->n)
	{
		return (0);
	}

	if (tree->left != NULL && tree->left->n > tree->n)
	{
		return (0);
	}

	if (tree->right != NULL && check_max(tree->right) == 0)
	{
		return (0);
	}

	if (tree->left != NULL && check_max(tree->left) == 0)
	{
		return (0);
	}

	return (1);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a max heap
 * @tree: tree to be evaluated
 *
 * Return: 1 if tree, 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (binary_tree_is_complete(tree) == 0)
	{
		return (0);
	}

	return (check_max(tree));
}
