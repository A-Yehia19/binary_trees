#include "binary_trees.h"


/* complete binary tree: */
/*   tree with levels of the tree are filled completely except */
/*   the lowest level nodes which are filled from as left as possible. */


/**
 * is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: return 1 if node is a aleaf, otherwise 0
*/
int is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);	
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is complete, otherwise 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	
	/* if root is a leaf */
	if (is_leaf(tree))
		return (1);

	/* if left most is filled with leaf (last level) */
	else if (tree->left != NULL && tree->right == NULL && is_leaf(tree->left))
		return (1);

	/* if right branch is filled and left isnt then not complete */
	else if (tree->left == NULL && tree->right != NULL)
		return (0);
	
	left = binary_tree_is_complete(tree->left);
	right = binary_tree_is_complete(tree->right);
	return(left & right);
}

/* code not fully optimal */