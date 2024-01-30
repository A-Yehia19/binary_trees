#include "binary_trees.h"


/*
perfect binary tree:
	Special type of binary tree in which all the leaf nodes are
	at the same depth, and all non-leaf nodes have two children.
*/

/**
 * node_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of this tree
*/
size_t node_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;
	size_t height;

	/* if no tree */
	if (tree == NULL)
		return (0);

	right_height = node_height(tree->right);
	left_height = node_height(tree->left);

	if (right_height > left_height)
		height = right_height;
	else
		height = left_height;

	return (1 + height);
} /* from 9-binary_tree_height.c */

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is perfect, otherwise 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* if no tree */
	if (tree == NULL)
		return (0);
	
	if (node_height(tree->right) != node_height(tree->left))
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_perfect(tree->left) & binary_tree_is_perfect(tree->right));
}
