#include "binary_trees.h"

/**
 * binary_tree_postorder - order through  binary by tree post-order traversal.
 *
 * @tree: points to the root node of the tree to traverse
 * @func: points to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
