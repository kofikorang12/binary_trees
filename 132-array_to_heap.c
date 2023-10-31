#include "binary_trees.h"

/**
 * array_to_heap - turns an array into a max heap
 * @array: array of values
 * @size: size of array
 *
 * Return: root of new tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *tree = NULL;

	for (i = 0; i < size; i++, array++)
	{
		heap_insert(&tree, *array);
	}

	return (tree);
}
