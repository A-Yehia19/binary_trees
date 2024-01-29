#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of this tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;
	size_t height;

	/* if no tree */
	if (tree == NULL)
		return (0);

	/* if leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	right_height = binary_tree_height(tree->right);
	left_height = binary_tree_height(tree->left);

	if (right_height > left_height)
		height = right_height;
	else
		height = left_height;

	return (1 + height);
}
