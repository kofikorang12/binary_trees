#include "binary_trees.h"

/**
 * modified_bst_insert - inserts of node into a avl tree
 * @tree: tree to be operated on
 * @array: array of value(s)
 * @size: size of array
 *
 * Return: root or tree
 */
bst_t *modified_bst_insert(bst_t **tree, int *array, size_t size)
{
	bst_t *parent = *tree;
	bst_t *child = *tree;
	int half_index = (size - 1) / 2;
	int value = array[half_index];

	if (tree == NULL)
	{
		return (NULL);
	}

	if (size == 0)
	{
		return (*tree);
	}

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
		{
			return (NULL);
		}

		if (half_index == 0)
		{
			return (*tree);
		}

		if (modified_bst_insert(tree, array, half_index) == NULL)
		{
			return (NULL);
		}
		if (modified_bst_insert(tree, array + half_index + 1,
					size - half_index - 1) == NULL)
		{
			return (NULL);
		}

		return (*tree);
	}

	while (child != NULL)
	{
		parent = child;

		if (value < parent->n)
		{
			child = parent->left;
		}
		else
		{
			child = parent->right;
		}
	}

	child = binary_tree_node(parent, value);
	if (child == NULL)
	{
		return (NULL);
	}

	if (value < parent->n)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	if (half_index == 0)
	{
		return (*tree);
	}

	if (modified_bst_insert(tree, array, half_index) == NULL)
	{
		return (NULL);
	}
	if (modified_bst_insert(tree, array + half_index + 1,
				size - half_index - 1) == NULL)
	{
		return (NULL);
	}

	return (*tree);
}

/**
 * sorted_array_to_avl - turns a sorted array into an avl tree
 * @array: array of value
 * @size: size of array
 *
 * Return: new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	return (modified_bst_insert(&tree, array, size));
}
