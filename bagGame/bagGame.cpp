////////////////////////////////////////////
//whatsInTheBag.cpp
//Summary: The program creates 5 random numbers and stores them in an Bag array[]
//        the user has to guess all the numbers in the array.
//output: wheter the user guess the correct guess or not, and th enumber guessed
//input: users difficulty level and users guess
//
//date created: 4/25/14
////////////////////////////////////////////

#include<iostream>
#include"Bag.h"
#include<string>
#include<random>
#include <ctime>
#include <string>

using namespace std;

//portotype//
void instructions();
//preconditions: ran in main;
//process: displays the rules of the game
//postconditions: none

void checkNum(Bag& bag1, int& lifesLeft, int& amountOfGuess, int numbersGuessed[]);
//preconditions: have created an instance of the Bag class.
//process: checks if the number guessed is in the bag instance.
//         it updates the numbers guessed.
//
//postconditions: none

int main()
{
	Bag bag1;
	int lifesLeft = 10,
    amountOfGuess = 0,
    numbersGuessed[10],
    difficulty;
	string repeat;
    
	instructions();
    
	cout << "\n\n\tChoose difficulty level\n"
    << "Choose 1 for easy(10 tries)\n"
    << "Choose 2 for normal(8 tries)\n"
    << "Choose 3 for hard(6 tries)\n";
    
	cin >> difficulty;
    
	switch (difficulty)
	{
        case 1: lifesLeft = 10;
            break;
        case 2: lifesLeft = 8;
            break;
        case 3: lifesLeft = 6;
            break;
        default:
            break;
	}
    
	do
	{
		srand(unsigned(time(NULL)));
		int randInt;
		for(int i = 0; i < 5; i++)
		{
			randInt = (rand() % 10 + 1);
			bag1.insert(randInt);
		}
        
		while(lifesLeft > 0)
		{
			if(bag1.size() == 0)
				break;
			checkNum(bag1, lifesLeft, amountOfGuess, numbersGuessed);
		}
        
		if(lifesLeft == 0 && bag1.size() == 0)
			cout << "\n\tYou Won the Game!!!\n";
		else if(lifesLeft == 0 && bag1.size() > 0)
			cout << "\n\tYou Lost the Game!!!\n";
        
		cout << "\nWould you like to play again? ";
		cin >> repeat;
        
	}while(repeat == "yes" || repeat == "Yes");
    
    
	system("pause>nul");
	return 0;
}

void instructions()
{
	cout << "\tWelcome to the Guessing Game\n"
    << "The game will give you a certain amount of tries to guess all\n"
    << "5 numbers (from 1 to 10)in the bag.\n";
    
	return;
}

void checkNum(Bag& bag1, int& lifesLeft , int& amountOfGuess, int numbersGuessed[])
{
	int guess, numErased;
	
	cout << "What number would you like to guess? ";
	cin >> guess;
	
	numbersGuessed[amountOfGuess] = guess;
    
	amountOfGuess++;
    
	lifesLeft--;
    
	numErased = bag1.erase(guess);
    
	if(numErased > 0)
	{
		cout << "\n\nGood Job!!!\n"
        << "You erased " << numErased << " number(s) from the bag.\n"
        << "There is now " << bag1.size() << " numbers in the bag.\n\n";
		cout << "You now have " << lifesLeft << " tries left.\n\n";
	}
	else
	{
		cout << "\n\nSorry the number was not in the bag\n"
        << "The amuont of numbers left in the bag are "
        << bag1.size() << endl << endl;
		cout << "You now have " << lifesLeft << " tries left.\n\n";
	}
    
	cout << "Numbes guessed:\n";
	for(int c = 0; c < amountOfGuess; c++)
	{
		cout << numbersGuessed[c] << " ";
	}
    
    
	
	system("pause>nul");
	system("CLS");
	return;
}