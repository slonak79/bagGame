#include "bag.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
string Intro();
bool level1();
bool level2();
bool level3();

int main()
{
	srand(unsigned(time(NULL)));
	char tryAgain = 'n';
	bool level1Passed = false,
    level2Passed = false,
    level3Passed = false;
	string user;
	user = Intro();
	cout << "Let's begin the game " << user << endl;
	level1Passed = level1();
	if (level1Passed)
	{
		level2Passed = level2();
	}
    
	if (level2Passed)
	{
		level3Passed = level3();
	}
    
	if (!level1Passed || !level2Passed || !level3Passed)
	{
		cout << "Enter 'y' to try again: ";
		cin >> tryAgain;
		do
		{
            
			level1Passed = level1();
			if (level1Passed)
			{
				level2Passed = level2();
			}
			else
			{
				cout << "Enter 'y' to try again: ";
				cin >> tryAgain;
			}
            
			if (level2Passed)
			{
				level3Passed = level3();
			}
			else
			{
				cout << "Enter 'y' to try again: ";
				cin >> tryAgain;
			}
            
		} while (tryAgain == 'y');
	}
	system("pause>null");
	return 0;
}

string Intro()
{
	string playerName;
	cout << "\tWelcome to ALIEN ABDUCTION!!\n"
    << "Begin by entering your game name: ";
	cin >> playerName;
	
    
	cout << "                    _.-'~~~~'-._    \n"
    << "                . - ~\\__ / \\__ / ~- .\n"
    << "                . - ~(oo)  (oo)~- .\n"
    << "              (_____//~~\\\\//~~\\\\______)\n"
    << "       _. - ~`                         `~ - ._\n"
    << "/ O = O = O = O = O = O = O = O = O = O = O = O = O = O\ \n"
    << "\\______________________________________________________/\n"
    << "                  \\ x x x x x x x /\n"
    << "                   \\ x_x_x_x_x_x /\n"
    << "                     : | . | ' .'.\n"
    << "	            | | . '. |:|::\n"
    << "                    | : | : .; |::\n"
    << "		    . | : . | :::|\n"
    << "                    | . | : . ||::\n"
    << "                    : | . | . ::::\n"
    << "                    |.: |. :. |:::\n"
    << "                     : | ___ | : |\n"
    << "                   (\\. | (___)   /)\n"
    << "                    \\\\  (_O O_) //\n"
    << "                     \\\\.\(_\\O/_) / \n"
    << "                    : | \\/\\_/\\/ :|\n"
    << "                    : | .(_ _) : |\n"
    << "                    :. | /   \\ | :\n"
    << "                    ::| /_____\\. |\n"
    << "                    :: . | | | .:|\n"
    << "                    :::| | | ||::|\n"
    << "                    :| : |_|_| . :\n"
    << "                    . : <_ | _> .: \n";
	cout << "This girl has been abducted by aliens! :O\n"
    << "Your mission is to save her by guessing the aliens' code values\n"
    << "You have 3 levels to pass! Good luck :)\n\n";
	return playerName;
}

bool level1()
{
	int guess;
	Bag level1Bag;
	int level1Vals;
	int count = 0;
	int ara[5];
	int vals;
	int rightCount = 0;
	cout << "\n\n\tLEVEL 1\n"
    << "There are 5 code values in the range from 1-10\n"
    << "Your goal is to guess 2 code values\nYou have 4 tries\n";
	for (int i = 0; i <= 5; i++)
	{
		level1Vals = rand() % 10 + 1;
		level1Bag.insert(level1Vals);
        
	}
	for (int k = 0; k < 5; k++)
	{
		cout << level1Bag.showOne(k) << endl;
	}
    
	for (int k = 0; k < 5; k++)
	{
		vals = level1Bag.showOne(k);
		ara[k] = vals;
	}
    
	for (int l = 0; l < 4; l++)
	{
		cout << "Enter guess # " << l + 1 << ": ";
		cin >> guess;
		
		rightCount = 0;
		int erase = level1Bag.erase(guess);
        
		if (erase >= 1)
		{
			cout << "\nRight guess\n";
			count++;
		}
		
		else
			cout << "\nWrong guess\n";
		if (count == 2)
		{
			break;
		}
        
	}
    
	if (count == 2)
	{
		cout << "\nYou passed level 1! :D\n";
		return true;
	}
	else
	{
		cout << "\nYou have failed the mission!\n"
        << "The girl has been eaten by the aliens! :(\n";
		return false;
	}
    
}

bool level2()
{
	int guess;
	Bag level2Bag;
	int level2Vals;
	int count = 0;
	int ara[10];
	int vals;
	int rightCount = 0;
	cout << "\n\n\tLEVEL 2\n"
    << "There are 10 code values in the range from 1-20\n"
    << "Your goal is to guess 5 code values\nYou have 7 tries\n";
	
    
	for (int i = 0; i <= 10; i++)
	{
		level2Vals = rand() % 20 + 1;
		level2Bag.insert(level2Vals);
        
	}
	for (int k = 0; k < 10; k++)
	{
		cout << level2Bag.showOne(k) << endl;
	}
    
	for (int k = 0; k < 10; k++)
	{
		vals = level2Bag.showOne(k);
		ara[k] = vals;
	}
    
	for (int l = 0; l < 7; l++)
	{
		cout << "Enter guess # " << l + 1 << ": ";
		cin >> guess;
        
		rightCount = 0;
		int erase = level2Bag.erase(guess);
        
		if (erase >= 1)
		{
			cout << "\nRight guess\n";
			count++;
		}
        
		else
			cout << "\nWrong guess\n";
		if (count == 5)
		{
			break;
		}
        
	}
    
	if (count == 5)
	{
		cout << "\nYou passed level 2!\n"
        << "You're so close to saving her!\n";
		return true;
	}
	else
	{
		cout << "\nYou have failed your mission!\n"
        << "The girl has been eaten by the aliens!\n";
		return false;
	}
}

bool level3()
{
	int guess;
	Bag level3Bag;
	int level3Vals;
	int count = 0;
	int ara[30];
	int vals;
	int rightCount = 0;
	cout << "\n\n\tLEVEL 3\n"
    << "There are 30 code values in the range from 1-50\n"
    << "Your goal is to guess 10 code values\n"
    << "You have 11 tries.\n";
    
	for (int i = 0; i <= 30; i++)
	{
		level3Vals = rand() % 50 + 1;
		level3Bag.insert(level3Vals);
        
	}
	for (int k = 0; k < 30; k++)
	{
		cout << level3Bag.showOne(k) << endl;
	}
    
	for (int k = 0; k < 30; k++)
	{
		vals = level3Bag.showOne(k);
		ara[k] = vals;
	}
    
	for (int l = 0; l < 11; l++)
	{
		cout << "Enter guess # " << l + 1 << ": ";
		cin >> guess;
        
		rightCount = 0;
		int erase = level3Bag.erase(guess);
        
		if (erase >= 1)
		{
			cout << "\nRight guess\n";
			count++;
		}
        
		else
			cout << "\nWrong guess\n";
		if (count == 10)
		{
			break;
		}
        
	}
    
	if (count == 10)
	{
		cout << "\n\n\tCONGRATULATIONS! You have saved the girl!!\n"
        << "\tYyyyyyaaaaaaayyyyy!!!!! :D :D :D \n";
		return true;
	}
	else
	{
		cout << "\nYou failed!!\nNow the girl has been eaten by the aliens :(\n";
		return false;
	}
}