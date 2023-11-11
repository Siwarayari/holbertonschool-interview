#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_node - function that creates a binary tree node
 * @value: is the value to put in the new node
 * @parent: Pointer to the parent node
 * Return: new_node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;
new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;
return (new_node);
}
/**
 * sortArrayToAVL - function that builds an AVL tree from an array
 * @array: array is a pointer to the first element of the array to be converted
 * @start: array is a pointer to the first element of the array to be converted
 * @end: size is the number of element in the array
 * Return: return a pointer to the node of the created AVL tree or NULL
*/
avl_t *sortArrayToAVL(int *array, int start, int end)
{
avl_t *newnode;
int middle = (start + end) / 2;

if (start > end)
{
return (NULL);
}

newnode = binary_tree_node(NULL, array[middle]);
if (newnode == NULL)
return (NULL);

newnode->left = sortArrayToAVL(array, start, middle - 1);

newnode->right = sortArrayToAVL(array, middle + 1, end);

if (newnode->left)
newnode->left->parent = newnode;

if (newnode->right)
newnode->right->parent = newnode;

return (newnode);
}
/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: array is a pointer to the first element of the array to be converted
 * @size: size is the number of element in the array
 * Return: return a pointer to the node of the created AVL,or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (!array || !size)
return (NULL);
return (sortArrayToAVL(array, 0, size - 1));
}
