#include "binary_trees.h"

/**
 * binary_tree_balance - measure  balance factor of a binary tree
 *
 * @tree:  points to  root node of  tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measure height of a binary tree
 *
 * @tree: A points to  root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef_tree = 0, rig_tree = 0;

		lef_tree = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rig_tree = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((lef_tree > rig_tree) ? lef_tree : rig_tree);
	}

	return (0);
}
