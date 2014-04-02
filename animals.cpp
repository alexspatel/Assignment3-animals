/*

	  FILE: useful.cpp

	  AUTHOR: Alex Patel

	  For CSCI 262 Spring 2014, Assignment 3, 20 questions  

*/

#include <iostream>
#include <cstdlib>
#include "animal2.h"

using namespace std;


// takes user input for an animal
void eat_line()
{
	char next;
	
	do {
		cin.get(next);
	} while (next != '\n');
}

// takes user input for y/n
bool inquire(const char query[])
{
	char answer;

	do
	{
		cout << query << " [y/n]" << endl;
		cin >> answer;
		cout << endl;
		answer = toupper(answer); // convert lowercase to uppercase
		eat_line(); // call eat_line function
	}
	while ((answer != 'Y') && (answer != 'N'));
	return (answer == 'Y');
}

