#pragma once
#include "Human.h"
#include "iostream"
#include "string"
using namespace std;
class Employee: protected Human
{
protected:
	int empID;
	string compName;
	string *languages;
	int salary;	int number;
public:
	Employee(string a, int b);
	Employee();
	~Employee();
	Employee(string a, int b, int c, string d, string e[], int f,int g);
	void print();
	void setempID(int a);
	int getempID();
	void setcompName(string a);
	string getcompName();
	void setlang(string *a, int b);
	string * getlang();
	void setsalary(int a);
	int getsalary();
	

};



