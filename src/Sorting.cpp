//============================================================================
// Name        : Sorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;



ifstream in("in.txt");
ofstream out("out.txt");

ifstream inf("in.txt", ifstream::binary);

ifstream inS("sourceFile.txt");
ofstream outS("sourceFile.txt");

ifstream inT("tempFile.txt");
ofstream outT("tempFile.txt");



void printNStringFromFile(int N, vector<pair<int, int>> initVec, ifstream &input, ofstream &output)
{

	int curPos = 0;
	string tempInput = "2546";

	for(vector<pair<int, int>>::iterator it = initVec.begin(); it < initVec.begin() + N; it++)
	{
		curPos += it->second + 1;
	}

	input.seekg(curPos);
	output << input.tellg() << endl;
	getline(input, tempInput);

	output << tempInput << endl;


}

void printVector(vector<int> vec, ofstream &output)
{
	for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		output << *(it) << endl;
	}
	output << endl;
}

int stringToInt(string s)
{
	int result, digit;

	for(int i = 0; i < s.length(); i++)
	{
		digit = (int)s[i] - 48;

		result += digit * pow(10, s.length() - i - 1);
	}

	return result;
}

vector<pair<int, int>> getStringInfo(ifstream &input)
{
	vector<pair<int, int>> vec;
	pair<int, int> tempPair;

	string tempStr = "", tempInput;

	while(!input.eof())
	{
		getline(input, tempInput);

		if(tempInput != "")
		{
			for(int i = 0; tempInput[i] != ' '; i++)
			{
				tempStr += tempInput[i];
			}

			tempPair.first = stringToInt(tempStr);
			tempPair.second = tempInput.length();
			vec.push_back(tempPair);
			tempStr = "";
		}
	}

	return vec;
}


int main()
{
	vector<pair<int, int>> stringInfoVector;

	stringInfoVector = getStringInfo(in);

	for(vector<pair<int, int>>::iterator it = stringInfoVector.begin(); it < stringInfoVector.end(); it++)
	{
		out << it->first << "\t" << it->second << endl;
	}

	printNStringFromFile(2, stringInfoVector, inf, out);
	printNStringFromFile(10, stringInfoVector, inf, out);
	printNStringFromFile(15, stringInfoVector, inf, out);


	return 0;
}
