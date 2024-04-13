#include "binary_trees.h"

/**
 * binary_tree_inorder - order through a binary tree using in-order traversal.
 *
 * @tree:  points to the root node of tree to traverse
 * @func: points to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
