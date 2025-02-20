#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - check if binary tree is a  AVL Tree.
 *
 * @tree: points to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - check if a binary tree is a  AVL tree.
 * @tree: poins to the root node of the tree to check.
 * @lo: value of the smallest node visited thus far.
 * @hi: value of the largest node visited this far.
 *
 * Return: If the tree is a  AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t left_hgt, right_hgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		left_hgt = height(tree->left);
		right_hgt = height(tree->right);
		diff = left_hgt > right_hgt ? left_hgt - right_hgt : right_hgt - left_hgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - measure height of a binary tree.
 * @tree: points to root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
