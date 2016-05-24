/* this header file holds the hang man graphics*/


#include <iostream>

using namespace std;


string WrongAnswer0();
string WrongAnswer1();
string WrongAnswer2();
string WrongAnswer3();
string WrongAnswer4();
string WrongAnswer5();
string WrongAnswer6();

string GetGraphics(int wrongAnswers)
{
	string hangGraphics;
	
	switch(wrongAnswers)
	{
		case 0:
			hangGraphics = WrongAnswer0();
			break;
		case 1:
			hangGraphics = WrongAnswer1();
			break;
		case 2:
			hangGraphics = WrongAnswer2();
			break;
		case 3:
			hangGraphics = WrongAnswer3();
			break;
		case 4:
			hangGraphics = WrongAnswer4();
			break;
		case 5:
			hangGraphics = WrongAnswer5();
			break;
		case 6:
			hangGraphics = WrongAnswer6();
			break;
		default:
			hangGraphics = "Something Went Wrong";
			break;
	}
	
	return hangGraphics;
}


string WrongAnswer6()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |             --|--\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=   	  "   |              / \\\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer5()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |             --|--\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=   	  "   |              / \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer4()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |             --|--\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=   	  "   |              \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer3()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |             --|\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=   	  "   |              \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer2()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=   	  "   |              \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer1()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |              ( )\n";
	hangGraphics +=       "   |                \n";
	hangGraphics +=       "   |                \n";
	hangGraphics +=   	  "   |              \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}

string WrongAnswer0()
{
	string hangGraphics = "   _________________\n";
	hangGraphics +=       "   |               |\n";
	hangGraphics +=       "   |                \n";
	hangGraphics +=       "   |                \n";
	hangGraphics +=       "   |                \n";
	hangGraphics +=   	  "   |              \n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=   	  "   |\n";
	hangGraphics +=		  "___|_______________________";		
	return hangGraphics;
}
string TitleScreen()
{
	string hangGraphics = "\t            _________________\n";
	hangGraphics +=       "\t            |               |\n";
	hangGraphics +=       "\t            |              ( )\n";
	hangGraphics +=       "\t Welcome    |             --|--\n";
	hangGraphics +=       "\t  To        |               |\n";
	hangGraphics +=   	  "\t   Hangman  |              / \\\n";
	hangGraphics +=   	  "\t            |\n";
	hangGraphics +=   	  "\t            |\n";
	hangGraphics +=		  "\t____________|_______________________";		
	return hangGraphics;
}
