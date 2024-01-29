#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes in this tree
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* if no tree */
	if (tree == NULL)
		return (0);

	/* if leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
