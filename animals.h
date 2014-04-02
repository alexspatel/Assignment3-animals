/*

	  FILE: animals.h

	  AUTHOR: Alex Patel

	  For CSCI 262 Spring 2014, Assignment 3, 20 questions  

*/

#ifndef ANIMALS_H
#define ANIMALS_H
#include <cstdlib>

template <class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

template <class T>
BinaryTreeNode<T>* create_node
(
 const T& entry,
 BinaryTreeNode<T>* l_ptr,
 BinaryTreeNode<T>* r_ptr
 );

template <class T>
bool is_leaf(const BinaryTreeNode<T>& node);

template <class T>
void tree_clear(BinaryTreeNode<T>*& root_ptr);

template <class T>
BinaryTreeNode<T>* tree_copy(BinaryTreeNode<T>* root_ptr);

#include "bintree.template"
#endif
