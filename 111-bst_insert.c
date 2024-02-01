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
	/* if no tree was created*/
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);

		return (*tree);
	}

	/* already in the tree */
	if (value == (*tree)->n)
		return (NULL);

	/* should insert in the left branch */
	else if (value < (*tree)->n)
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);

			return ((*tree)->left);
		}
		else
			return (bst_insert(&((*tree)->left), value));

	/* should insert in the right branch */
	else
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->right == NULL)
				return (NULL);

			return ((*tree)->right);
		}
		else
			return (bst_insert(&((*tree)->right), value));
}
