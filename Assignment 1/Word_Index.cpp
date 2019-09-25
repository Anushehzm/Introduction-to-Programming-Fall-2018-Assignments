#pragma once

#include "pch.h"
#include "Word_Index.h"
#include <string> 
#include <iostream>
#include <fstream>
#include <ctype.h> //isalpha
using namespace std;

Word_Index::Word_Index()
{
	

	string line;
	string y = "";
	ifstream myfile;
	myfile.open("Question2.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			y = y + line;
		}
		myfile.close();

	}
	//cout << y << endl;
	int len = y.length();
	int word_length = 0;
	int e = 0;
	int x = 0;
	
	for (int i = 0; i < len; i++)
	{
		y[i] = tolower(y[i]);
		if ((isalpha((unsigned char)y[i])) || y[i] == '+' || y[i] == '-' || y[i] == '\'')
		{
			word_length++;
		}
		else
		{
			arr[e] = y.substr(x, word_length);

			x = i + 1;

			e++;
			word_length = 0;
		}
	}

	for (int u = 0; u < 499; u++)//removing any empty strings
	{
		if (arr[u] == "")
		{
			for (int r = u; r < 499; r++)
			{
				arr[r] = arr[r + 1];
				arr[r + 1] = "";
			}
		}
	}
	
	//removing duplicates
	for (int w = 0; w < 500; w++)
	{
		for (int p = w + 1; p < 499 - w; p++)
		{
			
			if (arr[w] == arr[p])
			{
				for (int r = p; r < 499; r++)
				{
					arr[r] = arr[r + 1];
					arr[r + 1] = "";
				}
			}
		}
		
	}

	/*for (int t = 0; t < 500; t++)
	{
		cout << arr[t] << " ";
	}*/

}

Word_Index::~Word_Index()
{
}

void Word_Index::printer()
{
	for (int i = 0; i < 500; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int e=0; e<500; e++)
	 {	
		line_no[e] = new int[500];
     }
	char chr;
	string y = "";
	ifstream myfile;
	myfile.open("Question2.txt");
	if (myfile.is_open()) //reads whole string
	{
		while (!myfile.eof())
		{
			myfile.get(chr);
			y = y + chr;
		}
		cout << y << endl;
		myfile.close();
	}
	

	string *arr1 = new string[500];
	int len = y.length();
	int word_length = 0;
	int e = 0;
	int x = 0;

	for (int i = 0; i < len; i++)
	{
		y[i] = tolower(y[i]);
		if ((isalpha((unsigned char)y[i])) || y[i] == '+' || y[i] == '-' || y[i] == '\'' || y[i]=='\n')
		{	
		
			word_length++;
		}
		else
		{
			//cout << y[i]<<"~";
			arr1[e] = y.substr(x, word_length);

			x = i + 1;

			e++;
			word_length = 0;
		}
	}
	for (int y = 0; y < 500; y++) //array with words and new lines 
	{
		cout << arr1[y] << " ";
	}

	for (int t = 0; t < 500; t++)
	{
		for (int g = 0; g < 500; g++)
		{
			if (arr[t] == arr1[g])
			{

			}
		}
	}
}

void Word_Index::sort() //working
{
	for (int x = 0; x < 499; x++)
	{
		for (int y = 0; y < 499 - x; y++)
		{
			if (arr[y].compare(arr[y+1]) > 0)

			{
				string temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}

		}
	}


	
	//checking
	for (int u = 0; u < 500;u++)
	{
		if (arr[u]!="")
		cout << arr[u] << " ";
	}
}