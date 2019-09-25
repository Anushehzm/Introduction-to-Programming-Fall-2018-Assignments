#pragma once

#include "Human.h"
#include <iostream>
#include <string>

//using namespace std;
class Student:protected Human
{
protected:
	int rollnum;
	std::string uniname;
	std::string * courses; 
	int stipend;
	int c_no;
public:
	Student();
	Student(string a, int b);
	~Student();
	Student(string a, int b, int c, string d, string e[], int f, int g);
	void print();
	int getrollnum();
	void setrollnum(int a);
	string getuniname();
	void setuniname(string a);
	string* getcourses();
	void setcourses(string a[], int g);
	int getstipend();
	void setstipend(int b);
};

