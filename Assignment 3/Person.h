#pragma once
#include "Human.h"
#include "iostream"
#include "string"
#include "Student.h"
#include "Employee.h"
#include "Businessman.h"
using namespace std;
class Person : protected Student, protected Employee, protected Businessman
{
private:
	bool is_student;
	bool is_employee;
	bool is_businessman;
	double total;
	string name;
	int age;
public:
	~Person();
	Person();
	Person(bool x, bool y, bool z, string a, int b, int c, string d, string e[], int f, int g, int h, string i, string j[], int k, int l, int m, string n, int o);
	void print();
	void setstudent(bool a);
	bool getstudent();
	void setemployee(bool a);
	bool getemployee();
	void setbusinessman(bool a);
	bool getbusinessman();
	double gettax();
	void setter();
	//friend void checker();
	
};