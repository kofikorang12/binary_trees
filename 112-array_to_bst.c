#include "binary_trees.h"

/**
 * array_to_bst - makes a binary search tree out of an array
 * @array: array to make tree with
 * @size: size of array
 *
 * Return: root of new tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++, array++)
	{
		bst_insert(&root, *array);
	}

	return (root);
}
