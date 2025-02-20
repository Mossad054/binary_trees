#include "binary_trees.h"

/**
 * binary_tree_leaves - Countleaves in a binary tree.
 *
 * @tree: points to the root node of the tree that counts number of leaves.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}

	return (leaves);
}
