/*
	FILE: main.cpp
	AUTHOR: Alex Patel
	
	For CSCI 262, Spring 2014, Assignment 3

	main.cpp file for the game 20 questions, with subject: animals

*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>
#include "animals.h"

using namespace std;

// FUNCTION PROTOTYPES
void instruct(); // instructions

binary_tree_node<string>* beg_tree(); // start questions/answers

void learn(binary_tree_node<string>*& leaf_ptr); // fill and save user input

void ask_move_q(binary_tree_node<string>*& current_ptr); // point to next question

void play(binary_tree_node<string>* current_ptr); // user writes question

void eat_line();

bool inquire(const char query[]);




int main() {
	
	//while (true) {
	//	int choice;
	//	cout << "Welcome to 20 questions!" << endl;
	//	cout << "  1) Play the game" << endl;
	//	cout << "  2) Save the game file" << endl;
	//	cout << "  3) Quit" << endl;
	//	cout << "Please make your selection: ";
	//	cin >> choice;

	//	switch (choice) {
	//	case 1:
	//		//play_game(root);
	//		read_game_tree();
	//		break;
	//	case 2:
	//		//save_game_tree(root);
	//		break;
	//	case 3:
	//		break;
	//	default:
	//		cout << "Sorry, I don't understand." << endl << endl;
	//	}
	//	if (choice == 3) break;
	//}
	
	binary_tree_node<string> *a_root_ptr;

	instruct(); // show the game instructions

	a_root_ptr = beg_tree(); // set the beginning tree

	do {
		play(a_root_ptr); // play the game
	} while( inquire("Shall we play again>") ); // play again until user enters no

	cout << "Thanks for playing!" << endl;


	//delete_game_tree(root);
	return 0;
}


void instruct() // game instructions
{
	cout << "Welcome to 20 questions!" << endl;
	cout << "  1) Play the game" << endl;
	cout << "  2) Save the game file" << endl;
	cout << "  3) Quit" << endl;
	cout << "Please make your selection: ";
}


template <class T>
binary_tree_node<string>* beg_tree()
{
	binary_tree_node<string> *root_ptr;
	binary_tree_node<string> *child_ptr;

	const string root_que("Are you a mammal?");
	const string left_que("Are you bigger than a dog?");
	const string right_que("Do you live underwater?");
	const string animal1("Horse");
	const string animal2("Squirel");
	const string animal3("Seahorse");
	const string animal4("Eagle");

	root_ptr = create_node(root_question); // position at root question

	child_ptr = create_node(left_que); // left question
	child_ptr->left = create_node(animal1); // left answer
	child_ptr->right = create_node(animal2); // right answer
	root_ptr->right = child_ptr;

	child_ptr = create_node(right_que); // right question
	child_ptr->left = create_node(animal3); // left answer
	child_ptr->right = create_node(animal4); // right answer
	root_ptr->right = child_ptr;

	return root_ptr;
}

template <class T>
void learn(binary_tree_node<string>*& leaf_ptr)
{
	string guess;
	string correct;
	string new_que;

	guess = leaf_ptr->data;
	cout << "You win! What animal are you?" << endl;
	getline(cin, correct); // enter correct animal

	// save the correct animal to file
	ofstream animalOUT;
	animalOUT.open("animalsO.txt");
	if(!animalOUT.is_open())
	{
		cout << "ERROR opening file" << endl;
	}
	else
	{
		animalOUT << correct << endl;
	}
	animalOUT.close();

	cout << "Please type yes or no (y/n) that will distinguish a" << endl;
	cout << correct << " from a " << guess << "." << endl;
	getline(cin, new_que); // enter correct question

	// save the new question to file
	ofstream questionOUT;
	questionOUT.open("questions.txt");
	if(!questionOUT.is_open())
	{
		cout << "ERROR opening question file" << endl;
	}
	else if( questionOUT.is_open())
	{
		questionOUT << new_que << endl;
	}
	questionOUT.close();

	leaf_ptr->data = new_que;
	cout << "As a " << correct << ", " << new_que << endl;
	if( inquire("Please answer") ) // if yes, set correct to rightside answer
	{
		leaf_ptr->left = create_node(correct);
		leaf_ptr->right = create_node(guess);
	}
	else
	{
		leaf_ptr->left = create_node(guess);
		leaf_ptr->right = create_node(correct);
	}
}

template <class T>
void ask_move_q(binary_tree_node<string>*& current_ptr)
{
	cout << current_ptr->data;

	if(inquire(" Please answer")) // if yes, position left ptr
	{
		current_ptr = current_ptr->left;
	}
	else
	{
		current_ptr = current_ptr->right;
	}
}

template <class T>
void play(binary_tree_node<string>* current_ptr) // play game
{
	cout << "Think of an animal, then press enter.";
	eat_line(); // hit enter key

	while(!is_leaf(*current_ptr)) // if current_ptr is not empty
	{
		ask_move_q(current_ptr); // move the current_ptr
	}

	cout << ("My guess is " + current_ptr->data); // guess
	if(!inquire(" Is that your animal?")) // if wrong
	{
		learn(current_ptr); // put q/a into tree
	}
	else
	{
		cout << "I win!" << endl; // otherwise you lost
	}
}

void eat_line()
{
	char next;
	do {
		cin.get(next);
	} while( next != 'n');

}

bool inquire( const char query[])
{
	char answer;

	do {
		cout << query << "[y/n]" << endl;
		cin >> answer;
		answer = toupper(answer);
		eat_line();
	} while( (answer != 'y' ) && (answer != 'n' ));
	return (answer == 'y');
}

