#include "binary_trees.h"


/* for more info about rotation:*/
/* https://upload.wikimedia.org/wikipedia/commons/1/15/Tree_Rotations.gif */


/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL)
		return (NULL);

	pivot = tree->left;

	/* rotation methode */
	tree->left = pivot->left;
	pivot->right = tree;

	/* modify the parents*/
	pivot->parent = tree->parent;
	tree->parent = pivot;
	if (tree->left != NULL)
		tree->left->parent = tree;

	return (pivot);
}
