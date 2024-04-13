#include "binary_trees.h"

/**
 * array_to_bst - build Binary Search Tree from an array
 *
 * @array: points to the first element of the array to be converted.
 * @size: number of element in the array.
 *
 * Return: points to the root node of the created BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (bst_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
