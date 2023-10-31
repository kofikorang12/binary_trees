#include "binary_trees.h"

/**
 * array_to_avl - turns an array into an avl trees
 * @array: array of values
 * @size: size of array
 *
 * Return: root of new tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree;

	tree = NULL;

	for (i = 0; i < size; i++, array++)
	{
		avl_insert(&tree, *array);
	}

	return (tree);
}
