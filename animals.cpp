/*
	FILE: animals.cpp

	AUTHOR: Alex Patel

	For CSCI 262, Spring 2014, Assignment 3

	.cpp file for the game 20 questions, with subject: animals
*/

#include "animals.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

// Constructor
template <class T>
binary_tree_node()
{
	root = NULL;
}

//// Destructor
//template <class T>
//~binary_tree_node()
//{
//
//}



template <class T>
void binary_tree_node::traverse(binary_tree_node<T>* root)
{
	if( root != NULL )
	{
		traverse(root->left);
		traverse(root->right);
	}
}


// Reads the game tree from the input file
template <class T>
void binary_tree_node<T>::read_game_tree()
{
	string qORa;
	string text;

	ifstream fin;
	fin.open("animals.txt");

	if( fin.is_open() ) 
	{
		while( !fin.eof() )
		{
			fin >> qORa;
			getline(fin,text);
		}
	}

	readFile.close();
}

// Remove a node from the tree
template <class T>
void binary_tree_node<T>::remove(binary_tree_node<T>*&root, string val)
{
	if( root == NULL ) return NULL;

	if( val < root->data ) remove( root->left, val );
	else if( val > root ->data ) remove(root->right, val );	

}



// insert a value into the tree by adding a new node
template <class T>
void binary_tree_node<T>::insert(binary_tree_node<T>*& root, string val)
{
	if( root == NULL ) root = new binary_tree_node<string>(val);
	else if( val < root->data ) insert(root->left, val);
	else if( val > root->data ) insert(root->right, val);
}




// read_preorder
template <class T>
void binary_tree_node<T>::read_preorder(ifstream &fin, binary_tree_node<T>*&root)
{
	if( fin == "Q" )  
	{
			root->left = new binary_tree_node();
			root->right = new binary_tree_node();
			read_preorder(fin, node->left);
	}
	else
	{
		root->left = new binary_tree_node();
		root->right = new binary_tree_node();
		read_preorder(fin, node->right);
	}
}
