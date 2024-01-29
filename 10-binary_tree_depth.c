#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of this node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* if no tree */
	if (tree == NULL)
		return (0);

	/* if root */
	if (tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
