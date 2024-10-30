#include "bst.h"
#include <stddef.h>  // For NULL
#include <stdlib.h>  // For malloc, free

#include "bst.h"
#include <stddef.h>  // For NULL
#include <stdlib.h>  // For malloc, free

void insert_into(struct Node** root, int value) {
	/* TODO: Implement this function! */

//==========DUPE_CHECK===============

//  a == current

	Node* a = *root;

	while(a != NULL)
	{
		if(value == a->value)
			return;

		else if(value < a->value)
			a = a->left;
		else
			a = a->right;
	}

//===========INSERTION===============

	Node* z = (Node*)malloc(sizeof(Node));
	z->value = value;
	z->left = z->right = NULL;

	struct Node* x = *root;
	struct Node* y = NULL;

	while(x != NULL)
	{
		y = x;

		if(z->value < x->value)
			x = x->left;

		else
			x = x->right;
	}

	if(y == NULL)
		*root = z;

	else if(z->value < y->value)
		y->left = z;

	else
		y->right = z;
}

void free_tree(struct Node* root) {
	/* TODO: Implement this function! */

if(root != NULL)
	{
		free_tree(root->left);
		free_tree(root->right);
		free(root);
	}
}

size_t size_of(const struct Node* root) {
	/* TODO: Implement this function! */

	if(root == NULL)
		return 0;
	else
		return(size_of(root->left) + 1 + size_of(root->right));
}

int* contents_of(const struct Node* root) {
	/* TODO: Implement this function! */

//x == current node && y == prev node

	size_t size = size_of(root);
	int* result = (int*)malloc(sizeof(int) * size);

	int* x = result;
	const Node* y = NULL;
	const Node* current = root;

	const Node** stack = (const Node**)malloc(sizeof(const Node*) * size);
	size_t stackIndex = 0;

	while(current != NULL || stackIndex > 0)
	{
		while(current != NULL)
		{
			stack[stackIndex++] = current;
			current = current->left;
		}

		if(stackIndex > 0)
		{
			current = stack[--stackIndex];
			*x = current->value;
			++x;
			current = current->right;
		}
	}

	free(stack);

	return result;
}

const struct Node* second_min_in(const struct Node* root) {
	/* TODO: Implement this function! */

//a == current

	if(root == NULL || (root->left == NULL && root->right == NULL))
		return NULL;

	const Node* a = root;

	while(a->left != NULL)
	{
		if(a->left->right == NULL)
			return a;

		a = a->left;
	}

	if(a->right == NULL)
		return a;

	a = a->right;

	while(a->left != NULL)
		a = a->left;

	return a;
}

void inorder_tree_walk(const struct Node* root)
{
	if(root != NULL)
	{
		inorder_tree_walk(root->left);
		cout << root->value << endl;
		inorder_tree_walk(root->right);
	}
}
