#pragma once
#include <string>
#include<iostream>
using namespace std;

class Word_Index
{
	string *arr= new string[500];
	int **line_no = new int*[500];

public:
	Word_Index();
	~Word_Index();
	void printer();
	void sort();
	
};

