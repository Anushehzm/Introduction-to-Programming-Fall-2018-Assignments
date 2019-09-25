#pragma once
#include "string"
using namespace std;
class Human
{
protected:
	string name;
	int age;
public:
	Human();
	Human(string a, int b);
	~Human();
	virtual void print()=0;
	string getname();
	void setname(string d);
	int getage();
	void setage(int r);
};

