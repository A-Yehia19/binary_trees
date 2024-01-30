#include "binary_trees.h"


/*
uncle:
	sibling of the parent node
*/

/**
 * node_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: return a pointer to the sibling node or NULL in error
*/
binary_tree_t *node_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		sibling = node->parent->right;
	else
		sibling = node->parent->left;

	return (sibling);
} /* from 17-binary_tree_sibling.c */

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: return a pointer to the uncle node or NULL in error
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	uncle = node_sibling(node->parent);

	return (uncle);
}
