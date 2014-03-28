/*
		FILE: animals.h
		AUTHOR: Alex Patel

		For CSCI 262, Spring 2014, Assignment 2

		Header file for the game, 20 questions, with subject: animals
*/

#ifndef ANIMALS_H
#define ANIMALS_H


#include <iostream>
#include <string>
#include <cstdlib>

template <class T>
class binary_tree_node {
public:
	T data;
	binary_tree_node<T>* left;
	binary_tree_node<T>* right;
	binary_tree_node<T>* root;


	binary_tree_node();		// constructor
	~binary_tree_node();	// destructor
	string play_game(binary_tree_node<string>* root);
	string save_game_tree(binary_tree_node<string>* root);
	string delete_game_tree(binary_tree_node<string>* root);
	void read_game_tree();
	void traverse(binary_tree_node<T>* root);
	void remove(binary_tree_node<T>*&root, T val);
	void insert(binary_tree_node<T>*&root, T val);
	binary_tree_node<T>* search(binary_tree_node<T>* root, T val);
private:
	node<string>* root;
};
#endif
