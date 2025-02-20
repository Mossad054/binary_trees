#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 *
 * @array: points to the first element of the array to be converted.
 * @size:  number of element in the array
 *
 * Return: points to the root node of the created AVL tre.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * aux_sort - creates the tree using the half element of the array.
 *
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int midd = 0;

	if (begin <= last)
	{
		midd = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[midd]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, midd - 1);
		root->right = aux_sort(root, array, midd + 1, last);
		return (root);
	}
	return (NULL);
}
