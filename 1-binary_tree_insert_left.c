#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a binary tree node in left branch
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node = parent->left;
	binary_tree_t *node = binary_tree_node(parent, value);

	if (node == NULL)
		return (NULL);

	if (left_node == NULL)
	{
		parent->left = node;
	}else{
		left_node->parent = node;
		node->left = left_node;
		parent->left = node;
	}

	return (node);
}
