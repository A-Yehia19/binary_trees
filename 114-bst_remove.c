#include "binary_trees.h"


/* in-order successor */
/*   means the least element greater than the target */
/*   AKA least of the right branch */


/**
 * BST_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing the value, or NULL if not found
*/
bst_t *BST_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	else if (tree->n < value)
		return (BST_search(tree->right, value));
	else
		return (BST_search(tree->left, value));
} /* from 113-bst_search.c */

/**
 * bst_remove - removes a node from a Binary Search Tree in-order successor
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: return a pointer to the new root after removing the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *successor;
	if (root == NULL)
        return root;
 
    /* search for node to be deleted */
    if (root->n > value) {
        root->left = bst_remove(root->left, value);
        return root;
    }
    else if (root->n < value) {
        root->right = bst_remove(root->right, value);
        return root;
    }

	/* node found */

	/* If one of the children is empty */
    if (root->left == NULL) {
        tmp = root->right;
		tmp->parent = root->parent;
        free (root);
        return tmp;
    }
    else if (root->right == NULL) {
        tmp = root->left;
		tmp->parent = root->parent;
        free (root);
        return tmp;
    }

	/* if have 2 children */

	/* Find successor */
	successor = root->right;
	while (successor->left != NULL) {
		successor = successor->left;
	}


	if (successor->parent != root)
		successor->parent->left = successor->right;
	else
		successor->parent->right = successor->right;

	root->n = successor->n;
	free (successor);
	return root;
}
