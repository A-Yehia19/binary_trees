#include "binary_trees.h"


/* balance factor: */
/*   difference between the height of the left and the right subtrees */


/**
 * branch_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of this tree
*/
size_t branch_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;
	size_t height;

	/* if no tree */
	if (tree == NULL)
		return (0);

	right_height = branch_height(tree->right);
	left_height = branch_height(tree->left);

	if (right_height > left_height)
		height = right_height;
	else
		height = left_height;

	return (1 + height);
} /* from 9-binary_tree_height.c */

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	/* if no tree */
	if (tree == NULL)
		return (0);

	/* if leaf node */
	left = branch_height(tree->left);
	right = branch_height(tree->right);

	return (left - right);
}
