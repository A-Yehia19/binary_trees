#include "binary_trees.h"


/* full binary tree: */
/*   tree with either zero or two child nodes for each node. */


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is full, otherwise 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* if no tree */
	if (tree == NULL)
		return (0);

	if ((!(tree->left) && tree->right) || (tree->left && !(tree->right)))
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_full(tree->left) & binary_tree_is_full(tree->right));
}
