/*
Name: Peter Johnson
Date: 5/7/2016
Description: This program allows a user to play a game of hangman with a single word

*/

#include "DataAccessor.h"
#include "HangmanGraphics.h"
#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

void playGame(string strWord);
string formatString(string strFormat);
char checkChar(char chCheck);
string getWord();

int main(int argc, char** argv) 
{
	//local variables
	string strChoice;
	string strWordPlay;
	
	//displaying title screen
	cout << TitleScreen() << endl << endl << endl;

	
	system("PAUSE");
	system ("CLS");
	
	//program loop
	do
	{
		strWordPlay = getWord();
		playGame(strWordPlay);
		cout << endl << "Would you like to play again? Enter any letter to play again or 'Q' to quit: ";
		cin >> strChoice;
	}while(strChoice != "Q" && strChoice != "q");
	
	return 0;
}

void playGame(string strWord)
{
	//Game Logic
	
	//Local Variables
	int nEndGameNumber = 6;
	Player userPlay;
	string strInput;
	bool bIsString;
	bool bIsLetter;
	bool bEndGame;
	bool bIsUsed;
	bool bIsInAns;
	char chLetterChoice;

	//setting correct answer
	userPlay.setCorrectAnswer(strWord);
	
	system ("CLS");
	
	//Showing word to guess and hangman
	cout << GetGraphics(userPlay.getWrongAnswers()) << endl;
	cout << endl << "Word: " << userPlay.getOutputString() << endl;
	
	//main loop, loops until game is over
	do
	{
		
		//get letter loop
		do
		{
			//setting default
			bIsLetter = true;
			
			//letter input
			cout << endl << "Please enter a letter: ";
			cin >> strInput;
			
			//getting only first character
			chLetterChoice = strInput.at(0);
			// uppercasing and checking if char is a letter
			chLetterChoice = checkChar(chLetterChoice);
			
			//if char is not letter, show error
			if(chLetterChoice == '0')
			{
				cout << endl << "Invalid Letter";
				bIsLetter = false;
			}
			
			
			//checks if letter has been used
			bIsUsed = userPlay.hasLetBeenUsed(chLetterChoice);
			if(bIsUsed)
			{
				cout << endl << chLetterChoice << " has been used.";
				bIsLetter = false;
			}
			
			
		}while(bIsLetter == false);
		
		
		
		//checks if letter is in answer
		bIsInAns = userPlay.isLetInAnswer(chLetterChoice);
		
		//if letter is not in answer adds to wrong answer total
		if(bIsInAns == false)
		{
			userPlay.addToWrongAnswer();
		}
		
		//adds letter to vector of used letters
		userPlay.addLettersUsed(chLetterChoice);
		
		//checks if game should end
		if(userPlay.getWrongAnswers() == nEndGameNumber || userPlay.isWinner() == true)
		{
			bEndGame = true;
		}
		else
		{
			bEndGame = false;
		}
		
		
		//clear screen
		system ("CLS");
		
		//displaying current hangman graphic
		cout << GetGraphics(userPlay.getWrongAnswers()) << endl;
		
		//displaying result of letter input
		if(bIsInAns == true)
		{
			cout << chLetterChoice << " was in the answer.";
		}
		else
		{
			cout << chLetterChoice << " was not in the answer.";
		}
		
		//showing current status of word
		cout << endl << "Word: " << userPlay.getOutputString() << endl;
		
		//showing wrong answers used
		cout << endl << "Wrong Letters Used: " << userPlay.getWrongLettersUsedString();
		
		
	}while(bEndGame == false);
	
	//checks whether user won or lost
	if(userPlay.isWinner())
	{
		cout << endl << "You Won! The answer was " << userPlay.getCorrectAnswer();
	}
	else
	{
		cout << endl << "Game Over, You Lost! The answer was " << userPlay.getCorrectAnswer();
	}

}

string formatString(string strFormat)
{
	//checks that string is only letters and uppercases answer
	for(int i = 0; i < strFormat.length(); i++)
	{

		if(isalpha(strFormat.at(i)) == false)
		{
			return "0";
		}
		
		strFormat.at(i) = char(toupper(strFormat.at(i)));
		
	}
	
	return strFormat;
}


char checkChar(char chCheck)
{
	//checks that char entered is letter and uppercases letter
	if(isalpha(chCheck) == false)
	{
		return '0';
	}

	return char(toupper(chCheck));
}

string getWord()
{
	//gets word to play
	
	//local variables
	string strInput = "default";
	char userChoice;
	bool bIsString;
	vector<string> vListOfWords = getData("words.txt");
	int nListLength;
	int nRandSelect;
	srand (time(NULL));
	
	//clearing screen and getting user choice
	system ("CLS");
	cout << "1. Provide word to play.";
	cout << endl << "2. Get word from word dictionary." << endl;
	cout << "Please Select One: ";
	cin >> userChoice;
	
	while(userChoice != '1' && userChoice != '2')
	{
		//loops if user doesn't enter valid choice
		cout << "Invalid Answer. Please provide a valid choice: ";
		cin >> userChoice;
	}

	//if user chooses to provide word
	if(userChoice == '1')
	{
		//loops until user enteres a valid word
		do
		{
			bIsString = true;
			cout << "Please enter a word: ";
			cin >> strInput;
			
			//sending string to be checked and formatted
			strInput = formatString(strInput);
			
			//if string is not valid displaying error
			if(strInput == "0")
			{
				bIsString = false;
				cout << "Invalid Word" << endl;
			}
			
			
		}while(bIsString == false);
	}
	//else if user chooses to get word from word list
	else if(userChoice == '2')
	{
		//getting size of vector
		nListLength = vListOfWords.size() - 1;
		
		//getting random number based on size of vector
		nRandSelect = rand() % (nListLength - 1) + 1;
		
		//getting string at location of random number
		strInput = vListOfWords.at(nRandSelect);
		
		//sending string to be formatted
		strInput = formatString(strInput);
	}
	else
	{
		cout << "Something went Wrong.";
	}
	
	return strInput;
}




