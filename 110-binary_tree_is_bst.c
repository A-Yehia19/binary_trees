#include <limits.h>
#include "binary_trees.h"


/* Properties of a Binary Search Tree: */
/* - The left subtree contains only values less than the parent */
/* - The right subtree contains only values greater than the parent value */
/* - The left and right subtree each must also be a binary search tree */
/* - There must be no duplicate values */


/**
 * is_BST - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @lower_limit: lower limit of the branch
 * @upper_limit: lower limit of the branch
 *
 * Return: return 1 if tree is a valid BST, and 0 otherwise
*/
int is_BST(const binary_tree_t *tree, int lower_limit, int upper_limit)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (lower_limit < tree->n && tree->n < upper_limit){
		left = is_BST(tree->left, lower_limit, tree->n);
		right = is_BST(tree->right, tree->n, upper_limit);
		return (left & right);
	}

	else
		return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_BST(tree, INT_MIN, INT_MAX));
}
