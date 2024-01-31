#include "binary_trees.h"

/**
 * node_depth - measures the depth of a node
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of this node
*/
size_t node_depth(const binary_tree_t *tree)
{
	/* if no tree */
	if (tree == NULL)
		return (0);

	/* if root */
	if (tree->parent == NULL)
		return (0);

	return (1 + node_depth(tree->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: return pointer to the lowest common ancestor node of the two nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = node_depth(first);
	depth_second = node_depth(second);

	/* if on same level */
	if (depth_first == depth_second)
		/* ancestor found */
		if (first == second)
			return ((binary_tree_t *)first); /* convert to non-const */

		/* ancestor is above them */
		else
			return (binary_trees_ancestor(first->parent, second->parent));

	/* else the deeper go up til they are on same level */
	else if (depth_first > depth_second)
		return (binary_trees_ancestor(first->parent, second));

	else
		return (binary_trees_ancestor(first, second->parent));
}
