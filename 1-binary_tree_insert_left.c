#include "binary_trees.h"

/**
 * binary_tree_node_new - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node_new(binary_tree_t *parent, int value)
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
 * binary_tree_insert_left - insert a binary tree node in left branch
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;
	binary_tree_t *node = binary_tree_node_new(parent, value);

	if (node == NULL)
		return (NULL);

	left_node = parent->left;

	if (left_node == NULL)
	{
		parent->left = node;
	}
	else
	{
		left_node->parent = node;
		node->left = left_node;
		parent->left = node;
	}

	return (node);
}
