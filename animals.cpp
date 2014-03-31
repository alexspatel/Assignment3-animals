/*
	FILE: animals.cpp
	AUTHOR: Alex Patel

	For CSCI 262, Spring 2014, Assignment 3

	Implementation file for the game 20 questions, with subject: animals

*/

#include "animals.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <queue>


using namespace std;



template <class T>
binary_tree_node<T>* create_node(const T& entry,binary_tree_node<T>* L_ptr = NULL,binary_tree_node<T>* R_ptr = NULL)
{
	binary_tree_node<T> *result_ptr;

	result_ptr = new binary_tree_node<T>;
	result_ptr->data = entry;
	result_ptr->left = L_ptr;
	result_ptr->right - R-ptr;

	return result_ptr;
}


template <class T>
bool is_leaf(const binary_tree_node<T>& node)
{
	return (node.left == NULL) && (node.right == NULL);
}



template <class T>
void tree_clear(const binary_tree_node<T>& node)
{
	if(root_ptr != NULL)
	{
		tree_clear(root_ptr->left);
		tree_clear(root_ptr->right);
		delete root_ptr;
	}
}



template <class T>
binary_tree_node<T>* tree_copy(binary_tree_node<T>* root_ptr)
{
	binary_tree_node<T> *l_ptr;
	binary_tree_node<T> *r_ptr;
	if( root_ptr == NULL )
	{
		return NULL;
	}
	else
	{
		l_ptr = tree_copy(root_ptr->left);
		r_ptr = tree_copy(root_ptr->right);
		return create_node(root_ptr->data, l_ptr, r_ptr);
	}
}

template <class T>
void remove(binary_tree_node<T>*& root, T val)
{
	if( root == NULL ) return NULL; // base case: item is not found

	// Find the item to delete, call remove recursively
	if( val < root->data) remove(root->left, val);
	else if( val > root->data) remove(root->right, val);

	// Case 1 and 2, no children and one child
	else
	{
		if( root->left == NULL || root->right == NULL )
		{
			binary_tree_node<T>* temp;
			if( root->left == NULL ) temp = root->right;
			else temp = root->left;
			delete root;
			root = temp;
		}
		// case 3, two children
		else 
		{
			binary_tree_node<T>* temp = root->left; 
			binary_tree_node<T>* parent = root; 

			while( temp->right != NULL )
			{
				parent = temp;
				temp = temp->right;
			}
			root->data = temp->date;

			if( parent == root ) root->left = temp->left;
			else parent->right = temp->left;

			delete temp;
		}
	}
}
