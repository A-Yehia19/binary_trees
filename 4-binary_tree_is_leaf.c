#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if this node is leaf
 * @node: node to check on
 *
 * Return: return 1 if node is a leaf, otherwise 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* check if node exists */
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
