#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of this tree
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;
	size_t height;

	/* if no tree */
	if (tree == NULL)
		return (0);

	right_height = tree_height(tree->right);
	left_height = tree_height(tree->left);

	if (right_height > left_height)
		height = right_height;
	else
		height = left_height;

	return (1 + height);
} /* from 9-binary_tree_height.c */

/**
 * do_one_level - apply function on the level that is specified
 * @tree: pointer to the root node of the tree to traverse
 * @func: function to call for each node
 * @level: the level of the tree to apply the function
 *
 * Return: NONE
*/
void do_one_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
		func(tree->n);
	else
	{
		do_one_level(tree->left, func, level - 1);
		do_one_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: function to call for each node
 *
 * Return: NONE
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);
	for (level = 0; level < height; level++)
		do_one_level(tree, func, level);
}
