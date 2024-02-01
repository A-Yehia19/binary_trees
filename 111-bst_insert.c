#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: return a pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	/* if no tree was created*/
	if(*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		if (node == NULL)
			return (NULL);

		*tree = node;
		return (node);
	}

	/* already in the tree */
	if (value == (*tree)->n)
		return(NULL);

	/* should insert in the left branch */
	else if (value < (*tree)->n){
		if ((*tree)->left == NULL)
		{
			node = binary_tree_node(*tree, value);
			if (node == NULL)
				return (NULL);

			(*tree)->left = node;
			return (node);
		}
		else
			return (bst_insert(&((*tree)->left), value));
	}
	/* should insert in the right branch */
	else
	{
		if ((*tree)->right == NULL)
		{
			node = binary_tree_node(*tree, value);
			if (node == NULL)
				return (NULL);

			(*tree)->right = node;
			return (node);
		}
		else
			return (bst_insert(&((*tree)->right), value));
	}
}
