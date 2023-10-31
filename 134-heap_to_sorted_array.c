#include "binary_trees.h"

/**
 * binary_tree_size - finds the size of a tree
 * @tree: tree to be evaluated
 *
 * Return: number of nodes 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * heap_to_sorted_array - turns a max heap into a sorted array
 * @heap: heap to be changed
 * @size: size array will be
 *
 * Return: array of heap's values
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int *arr_ptr;

	if (heap == NULL)
	{
		return (NULL);
	}

	*size = binary_tree_size(heap);
	if (*size == 0)
	{
		return (NULL);
	}

	array = malloc(sizeof(int *) * *size);
	if (array == NULL)
	{
		return (NULL);
	}
	arr_ptr = array;

	while (heap != NULL)
	{
		*arr_ptr = heap->n;
		arr_ptr++;
		heap_extract(&heap);
	}

	return (array);
}
