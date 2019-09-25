#pragma once
#include "Human.h"
#include "iostream"
#include "string"
using namespace std;
class Businessman: protected Human
{
protected:
	int regID;
	string compName;
	int Earning;
public:
	Businessman(string a, int b);
	Businessman();
	~Businessman();
	Businessman(string a, int b, int c, string d, int f);
	void print();
	void setregID(int a);
	int getregID();
	void setcompName(string a);
	string getcompName();
	void setEarning(int a);
	int getEarning();
	

};

