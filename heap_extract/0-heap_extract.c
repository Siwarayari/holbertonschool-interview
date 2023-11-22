#include "binary_trees.h"
/**
 * mv_down - move the tree down
 * @root: head of the tree
*/
void mv_down(heap_t *root)
{
	heap_t *larg = 0;
	int tmp = 0;

	if (root->right && root->left)
	{
		if (root->right->n > root->left->n)
			larg = root->right;
		else
			larg = root->left;
	}

	if (larg && larg->n > root->n)
	{
		tmp = larg->n;
		larg->n = root->n;
		root->n = tmp;
		mv_down(larg);
	}
}
/**
 * get_height - height of the tree
 * @root: head of the tree
 * Return: the height of the root
*/
int get_height(heap_t *root)
{
	int left_height = 0;
	int right_height = 0;

	if (root == NULL)
	{
		return (0);
	}

	else
	{
		left_height = get_height(root->left);
		right_height = get_height(root->right);

		return (max(left_height, right_height) + 1);
}
}
/**
 * get_last_node - get the last node of the tree
 * @root: head of the tree
 * @height: height of the tree
 * @count: counter
 * Return: the last node
*/
heap_t *get_last_node(heap_t *root, int height, int count)
{
	heap_t *left;
	heap_t *right;

	if (count < height)
	{
		left = get_last_node(root->left, height, count + 1);
		right = get_last_node(root->right, height, count + 1);
	}
	else
		return (root);

	if (right)
		return (right);
	return (left);
}
/**
 * get_last - function for getting the last node of the tree
 * @root: head of the tree
 * Return: get_last_node
*/
heap_t *get_last(heap_t *root)
{
	int height;

	height = get_height(root);

	return (get_last_node(root, height, 1));
}
/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: is a double pointer to the root node of the heap
 * Return: value or 0
*/
int heap_extract(heap_t **root)
{
	heap_t *lastnode;
	int value = 0;
	int tmp = 0;

	if (*root == NULL)
		return (0);

	value = (*root)->n;

	if ((*root)->left && (*root)->right != NULL)
	{
		lastnode = get_last(*root);
		tmp = (*root)->n;
		(*root)->n = lastnode->n;
		lastnode->n = tmp;
		if (lastnode->parent != NULL)
		{
			if (lastnode->parent->right == lastnode)
				lastnode->parent->right = NULL;
			else
				lastnode->parent->left = NULL;
		}
		mv_down(*root);
	} else
	{
		*root = NULL;
	}
	free(lastnode);
	return (value);
}
