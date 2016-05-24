/*
This header file stores the player class
The playing class is used to keep track of player information
*/


#include <iostream>
#include <vector>

using namespace std;

class Player
{
	private:
			int wrongAnswers; //holds the number of wrong answers
			string correctAnswer; //holds the correct answer
			vector<char> lettersUsed; //vector that holds the letters that have been played
	
	public:
			//default contructor
			Player()
			{
				wrongAnswers = 0;
			}
			
			Player(string strCorrectAnswer)
			{
				wrongAnswers = 0;
				correctAnswer = strCorrectAnswer;
			}
			
			
			//getting number of wrong answers
			int getWrongAnswers()
			{
				return wrongAnswers;
			}
			//setting number of wrong answers
			void setWrongAnswers(int nWrongAnswers)
			{
				wrongAnswers = nWrongAnswers;
			}
			//incrementing wrong answer count
			void addToWrongAnswer()
			{
				wrongAnswers++;
			}
			
			
			//getting correct answer
			string getCorrectAnswer()
			{
				return correctAnswer;
			}
			//set correct answer
			void setCorrectAnswer(string strCorrectAnswer)
			{
				correctAnswer = strCorrectAnswer;
			}


			//getting vector of letters used
			vector<char> getLettersUsed()
			{
				return lettersUsed;
			}
			//adding a letter to the vector
			void addLettersUsed(char cLetter)
			{
				lettersUsed.push_back(cLetter);
			}
			
			
			//getting a string that only shows the correct letters guessed in the answer
			string getOutputString()
			{
				//local variables
				string strOutput = correctAnswer;
				char chCurrent;
				bool bIsGuessed;
				
				//loops through each letter in answer
				for(int i = 0; i < strOutput.length(); i++)
				{
					chCurrent = strOutput.at(i);
					bIsGuessed = false;

					//loops through each letter in letters used vector to see if they match the current char
					for(int k = 0; k < lettersUsed.size(); k++)
					{
						if(chCurrent == lettersUsed.at(k))
						{
							bIsGuessed = true;
							break;
						}
					}
					
					//if letter has not been guessed replace it with *
					if(bIsGuessed == false)
					{
						strOutput.at(i) = '*';
					}
					
				}
				
				return strOutput;
			}
			
			
			//checks for winner
			bool isWinner()
			{
				//if result of getOuputString matches correct answer we can assume the player won
				if(correctAnswer == getOutputString())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			
			//checks if letter is in the answer
			bool isLetInAnswer(char chUserLetter)
			{
				//loop to check if played letter is in the answer
				for(int i = 0; i < correctAnswer.length(); i++)
				{
					if(chUserLetter == correctAnswer.at(i))
					{
						return true;
					}
				}
				
				return false;
			}
			
			
			//checks if letter is in the letters used vector
			bool hasLetBeenUsed(char chUserLetter)
			{
				//loop to check if played letter is in the letters used vector
				for(int i = 0; i < lettersUsed.size(); i++)
				{
					if(chUserLetter == lettersUsed.at(i))
					{
						return true;
					}
				}
				
				return false;
			}
			

			//gets a string of all the wrong letters used
			string getWrongLettersUsedString()
			{
				//local variable
				string strLettersUsed = " ";
				
				//loop that loops through each letter in vector
				for(int i = 0; i < lettersUsed.size(); i++)
				{
					if(isLetInAnswer(lettersUsed.at(i)) == false)
					{
						//adds letter to string
						strLettersUsed += lettersUsed.at(i);
						//space separates letters
						strLettersUsed += " ";
					}

				}
				
				return strLettersUsed;
			}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
};
