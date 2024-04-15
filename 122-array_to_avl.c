#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree.
 *
 * @array: points  first element of the array to be converted.
 * @size:  number of element in the array.
 *
 * Return: points to the root node of the created AVL tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t indx, jndex;

	if (array == NULL)
		return (NULL);

	for (indx = 0; indx < size; indx++)
	{
		for (jndex = 0; jndex < indx; jndex++)
		{
			if (array[jndex] == array[indx])
				break;
		}
		if (jndex == indx)
		{
			if (avl_insert(&tree, array[indx]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
