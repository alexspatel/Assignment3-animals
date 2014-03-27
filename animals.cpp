#include "animals.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;
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
