#include "binary_trees.h"

/**
 * binary_tree_new_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_new_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->right = NULL;
	node->left = NULL;

	return (node);
}

/**
 * binary_tree_insert_right - insert a binary tree node in right branch
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;
	binary_tree_t *node = binary_tree_new_node(parent, value);

	if (node == NULL || parent == NULL)
		return (NULL);

	right_node = parent->right;

	if (right_node == NULL)
	{
		parent->right = node;
	}
	else
	{
		right_node->parent = node;
		node->right = right_node;
		parent->right = node;
	}

	return (node);
}
