/*
		FILE: animals.h
		AUTHOR: Alex Patel

		For CSCI 262, Spring 2014, Assignment 3

		Header file for the game, 20 questions, with subject: animals
*/

#ifndef ANIMALS_H
#define ANIMALS_H


#include <iostream>
#include <string>
#include <cstdlib>

template <class T>
class binary_tree_node 
{
	T data;
	binary_tree_node<T>* left;
	binary_tree_node<T>* right;
};

template <class T>
binary_tree_node<T>* create_node
	( const T& entry,
	binary_tree_node<T>* Lptr,
	binary_tree_node<T>* Rptr
	);

template <class T>
bool is_leaf(const binary_tree_node<T>& node );

template <class T>
void tree_clear(binary_tree_node<T>*& root_ptr );

template <class T>
binary_tree_node<T>* tree_copy(binary_tree_node<T>* root_ptr );

template <class T>
void remove(binary_tree_node<T>*& root, T val);


#endif
