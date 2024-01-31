#include "binary_trees.h"


/* for more info about rotation:*/
/* https://upload.wikimedia.org/wikipedia/commons/1/15/Tree_Rotations.gif */


/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL)
		return (NULL);

	pivot = tree->right;

	/* rotation methode */
	tree->right = pivot->left;
	pivot->left = tree;

	/* modify the parents*/
	pivot->parent = tree->parent;
	tree->parent = pivot;
	if (tree->right != NULL)
		tree->right->parent = tree;

	return (pivot);
}
