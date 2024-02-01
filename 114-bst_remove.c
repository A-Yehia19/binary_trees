#include "binary_trees.h"


/* in-order successor */
/*   means the least element greater than the target */
/*   AKA least of the right branch */


/**
 * bst_remove_one_child - removes a node from a BST with one child
 * @root: pointer to the node to delete
 *
 * Return: new root node after removing the desired value
*/
bst_t *bst_remove_one_child(bst_t *root)
{
	bst_t *tmp;

	if (root->left == NULL)
	{
		tmp = root->right;
		if (tmp != NULL)
			tmp->parent = root->parent;
	}
	else if (root->right == NULL)
	{
		tmp = root->left;
		if (tmp != NULL)
			tmp->parent = root->parent;
	}
	free(root);
	return (tmp);
}

/**
 * bst_remove_two_child - removes a node from a BST with two childrens
 * @root: pointer to the node to delete
 *
 * Return: new root node after removing the desired value
*/
bst_t *bst_remove_two_child(bst_t *root)
{
	bst_t *successor;

	/* Find successor */
	successor = root->right;
	while (successor->left != NULL)
		successor = successor->left;

	if (successor->parent != root)
		successor->parent->left = successor->right;

	else
		successor->parent->right = successor->right;

	/* re-adjust parents */
	if (successor->right != NULL)
		successor->right->parent = successor->parent;

	root->n = successor->n;
	free(successor);
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree in-order successor
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: return a pointer to the new root after removing the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (root);

	/* search for node to be deleted */
	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	else if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}

	/* node found */

	/* If one of the children is empty */
	if (root->left == NULL || root->right == NULL)
		return (bst_remove_one_child(root));

	/* if have 2 children */
	return (bst_remove_two_child(root));
}
