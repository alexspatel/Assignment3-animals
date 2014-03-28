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
void binary_tree_node::traverse(binary_tree_node<string>* root)
{
	if( root != NULL )
	{
		// root -> data
		traverse(root->left);
		traverse(root->right);
	}
}


// Reads the game tree from the input file
template <class T>
void binary_tree_node::read_game_tree()
{
	string root_in;
	string left_in;
	string right_in;
	ifstream readFile;
	readFile.open("animals.txt");
	if( readFile.is_open() ) 
	{
		while( !readFile.eof() )
		{
			readFile >> root_in;
			readFile >> left_in;
			readFile >> right_in;
			cout << root_in << endl;
			cout << left_in << endl;
			cout << right_in << endl;
		}
	}

	readFile.close();
}

// Remove a node from the tree
template <class T>
void binary_tree_node::remove(binary_tree_node<string>*&root, string val)
{
	// BASE CASE: IF ITEM NOT FOUND, DO NOTHING
	if( root == NULL ) return NULL;

	// FIND THE ITEM TO DELETE
	if( val < root->data ) remove( root->left, val );
	else if( val > root ->data ) remove(root->right, val );
	
	// CASE 1 & 2: NO CHILDREN, ONE CHILD
	else // item found
	{
		if( root->left == NULL || root->right == NULL )
		{
			binary_tree_node<string>* temp;
			if( root->left == NULL ) temp = root->right;
			else temp = root->left;
			delete root;
			root = temp;
		}

		// CASE 3: TWO CHILDREN
		else
		{
			binary_tree_node<string>* temp = root->left; // find rightmost node
			binary_tree_node<string>* parent = root;	 // in left subtree
			while( temp->right != NULL )
			{
				parent = temp;
				temp = temp->right;
			}
			root->data = temp->data; // copy data to root

			if( parent == root )	 // detach and delete rightmost node
			{
				root->left = temp->left; // in left subtree
			}
			else
			{
				parent->right = temp->left;
			}
			delete temp;
		}
	}

}



// insert a value into the tree by adding a new node
template <class T>
void binary_tree_node::insert(binary_tree_node<string>*& root, string val)
{
	if( root == NULL ) root = new binary_tree_node<string>(val);
	else if( val < root->data ) insert(root->left, val);
	else if( val > root->data ) insert(root->right, val);
}


// search function
template  <class T>
binary_tree_node<T>* search(binary_tree_node<T>* root, T val)
{
	if( root == NULL ) return NULL;
	if( val == root->data ) return root;
	if( val < root->data ) return search( root->left, val );

	return search( root->right, val );
}
