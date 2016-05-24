/*
This Header file contains two functions, GetData and SaveData which access a file and retrieve the 
contents or place additional text into the file respectively.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void saveData(vector<string> vData, string strFileName, bool isAppendMode)
{
	//object instance
	ofstream fileOut;
	
	//open the file in specified mode
	if(isAppendMode)
	{
		fileOut.open(strFileName.c_str(),ios::app);	
	}
	else
	{
		fileOut.open(strFileName.c_str());
	}
	
	//dump vector into file
	for(int n = 0; n<vData.size();n++)
	{
		if(vData.at(n) != "")
		{
			//output name to file
			fileOut << vData.at(n) << endl;
		}

	}

	//close file
	fileOut.close();
	
}//end saveData

vector<string> getData(string strFileName)
{
	//object instance
	string strName;
	ifstream fileIn;
	vector<string> vData(1);
	
	//open file
	fileIn.open(strFileName.c_str());
	
	fileIn >> strName;
	
	// get data while looping through file
	while(!fileIn.eof())
	{
		vData.push_back(strName);
		fileIn >> strName;
	}
	
	//close file
	fileIn.close();
	
	return vData;
	
}//end getData
