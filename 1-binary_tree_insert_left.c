#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as the left-child of another node
 *
 * @parent: points to the node to insert the left child.
 * @value: value that stores the new node
 *
 * Return: points to the created node, NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
