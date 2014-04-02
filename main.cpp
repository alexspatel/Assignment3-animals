/*

	  FILE: main.cpp

	  AUTHOR: Alex Patel

	  For CSCI 262 Spring 2014, Assignment 3, 20 questions  

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <cstdlib>
#include <string>
#include "animals.h"
#include "animal2.h"
#include <queue>



using namespace std;

void instruct(); // the instructions

BinaryTreeNode<string>* beginning_tree();	// the starting questions and answers

void learn(BinaryTreeNode<string>*& leaf_ptr);	// fills in users input and saves it

void ask_and_move(BinaryTreeNode<string>*& current_ptr);	// moves pointer to next question if the question is answered with a no

void play(BinaryTreeNode<string>* current_ptr);	// asks user to think of a question

void save_tree(BinaryTreeNode<string>* p, ostream &out); // save the game tree to file

void write_to_file(BinaryTreeNode<string>* root_ptr); // creates a new file, calls the save_tree function





int main()
{
	cout << "Welcome to 20 questions!" << endl;

	BinaryTreeNode<string> *root_ptr;
	
	root_ptr = beginning_tree();	// set the beginning tree

	while (true)
	{
		int choice;
		instruct();	 // show insctructions
		cin >> choice;

		switch (choice) {
		case 1:
			play(root_ptr);
			break;
		case 2: 
			{
				write_to_file(root_ptr);
				break;
			}
		case 3:
			return 0;
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	cout << "Thanks for playing!" << endl;

	return 0;
}


// the game instructions
void instruct()		
{
	cout << "  1) Play the game" << endl;
	cout << "  2) Save the game tree" << endl;
	cout << "  3) Quit" << endl;
	cout << "Please make your selection: ";
}


BinaryTreeNode<string>* beginning_tree()
{
	queue<string> store;
	BinaryTreeNode<string> *root_ptr;
	BinaryTreeNode<string> *child_ptr;

	string root_que;
	string left_que;
	string right_que;
	string animal1;
	string animal2;
	string animal3;
	string animal4;

	// Read in the input file 
	ifstream fin;
	fin.open("AnimalINPUT.txt");

	if(fin.is_open())
	{
			getline(fin,root_que);
			//cout << root_que << endl;
			store.push(root_que);

			getline(fin,left_que);
			//cout << left_que << endl;
			store.push(left_que);

			getline(fin,right_que);
			//cout << right_que << endl;
			store.push(right_que);

			getline(fin,animal1);
			//cout << animal1 << endl;
			store.push(animal1);

			getline(fin,animal2);
			//cout << animal2 << endl;
			store.push(animal2);

			getline(fin,animal3);
			//cout << animal3 << endl;
			store.push(animal3);

			getline(fin,animal4);
			//cout << animal4 << endl;
			store.push(animal4);
			
	}

	fin.close(); // close the file


	root_ptr = create_node(root_que);	//position root_ptr at the root question
	
	child_ptr = create_node(left_que);	//make the left question
	child_ptr->left = create_node(animal1);	//make left answer
	child_ptr->right = create_node(animal2);	//make right answer
	root_ptr->left = child_ptr;

	child_ptr = create_node(right_que);	//make the right question
	child_ptr->left = create_node(animal3);	//make left answer
	child_ptr->right = create_node(animal4);	//make right answer
	root_ptr->right = child_ptr;
	
	return root_ptr;
}

void learn(BinaryTreeNode<string>*& leaf_ptr)//inserts answer and question into
{                                                 //the tree
	string guess_animal;
	string correct_animal;
	string new_question;

	guess_animal = leaf_ptr->data;
	cout << "Boo! I don't know!" << endl;
	cout << "What animal are you?" << endl;
	getline(cin, correct_animal);	//enter the correct animal
	correct_animal = "#A " + correct_animal;

	// Ask the user to expand the game tree
	if( inquire("Would you like to expand the game tree?") )
	{
		cout << "Enter a y/n question that will distinguish a " << endl <<
			correct_animal << " from a " << guess_animal << "." << endl;

		getline(cin, new_question);//enter the correct question
		new_question = "#Q " + new_question;
		cout << endl;

		//save the correct animal to a file
		ofstream animal_file;
		animal_file.open("Animals.txt");
		if(!animal_file.is_open())
			cout << "Error opening animal file!";
		else if (animal_file.is_open())
			animal_file << correct_animal << endl;
		animal_file.close();

		

		//save the new question to a file
		ofstream question_file;
		question_file.open("Questions.txt");

		if(!question_file.is_open())
			cout << "Error opening question file!";
		else if (question_file.is_open())
			question_file << new_question << endl;
		question_file.close();

		leaf_ptr->data = new_question;
		cout << "As a " << correct_animal << ", " << new_question << endl;
		if (inquire("Please answer"))	//if yes then set the correct animal to be the right side answer
		{                         
			leaf_ptr->left = create_node(correct_animal);
			leaf_ptr->right = create_node(guess_animal);
		}
		else //other wise make it the left side answer
		{
			leaf_ptr->left = create_node(guess_animal);
			leaf_ptr->right = create_node(correct_animal);
		}
		save_tree(leaf_ptr, question_file);
	
	}
}

void ask_and_move(BinaryTreeNode<string>*& current_ptr)	//reposition the pointer
{
	cout << current_ptr->data;
	if (inquire(" Please answer"))	// if answer is yes then position pointer left
		current_ptr = current_ptr->left;
	else //other wise move it to the right
		current_ptr = current_ptr->right;
}

void play(BinaryTreeNode<string>* current_ptr)	//play the game
{
	cout << "Think of an animal..." << endl;
	eat_line();	// user input
	
	while (!is_leaf(*current_ptr))	//if the current pointer is not empty
		ask_and_move(current_ptr);	//then move the current pointer

	cout << ("My guess is a(n) " + current_ptr->data) << endl;	//programs guess
	if (!inquire("Is this correct?"))	//if answers no
		learn(current_ptr);	//then put the answer and question into the tree
	else
		cout << "I win!" << endl << "************************" << endl;	//other wise tell user it knew it
}      

// function to save the binary tree to file using preorder traversal
void save_tree(BinaryTreeNode<string>* p, ostream &out)
{
	if(!p)	out << "";
	else
	{
		out << p->data << endl;
		save_tree(p->left, out);
		save_tree(p->right, out);
	}
}

void write_to_file(BinaryTreeNode<string>* root_ptr)
{
	ofstream output;
	output.open("saveFILE.txt");
	save_tree(root_ptr, output);
	output.close();	
	cout << endl << "saved to file: 'saveFILE.txt' " << endl << endl << endl;
}





