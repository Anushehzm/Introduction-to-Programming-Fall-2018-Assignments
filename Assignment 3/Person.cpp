#include "pch.h"
#include "Person.h"
#include "Human.h"
#include "iostream"
#include "string"
using namespace std;
Person::Person()
{
}
Person::Person(bool x, bool y, bool z, string a, int b, int c, string d, string e[], int f, int g, int h, string i, string j[], int k, int l, int m, string n, int o): Student(a,b,c,d,e,f,g), Employee(a,b,h,i,j,k,l), Businessman(a,b,m,n,o)
{
	name = a;
	age = b;
	setstudent(x);
	setemployee(y);
	setbusinessman(z);
	
}

Person::~Person()
{
}

void Person::print()
{
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	cout << "Is Student: " << getstudent() << endl;
	cout << "Is Employee: " << getemployee() << endl;
	cout << "Is Businessman: " << getbusinessman() << endl;
	if (getstudent() == true)
	{
		cout << "Printing student information: " << endl;
		Student::print();
		cout << endl;
		if (getstipend() > 50000)
		{
			t1 = getstipend()*0.02;
		}
	}
	if (getemployee() == true)
	{
		cout << "Printing employee information: " << endl;
		Employee::print();
		cout << endl;
		if (getsalary() > 50000 && getsalary() <= 100000)
		{
			t2 = getsalary()*0.05;
		}
		else if (getsalary() > 100000)
		{
			t2 = getsalary()*0.1;
		}
	}
	if (getbusinessman() == true)
	{
		cout << "Printing businessman information: " << endl;
		Businessman::print();
		cout << endl;
		if (getEarning() > 50000 && getEarning() <= 100000)
		{
			t3 = getEarning()*0.08;
		}
		else if (getEarning() > 100000)
		{
			t3 = getEarning()*0.12;
		}
	}
	if (getstudent() == false && getemployee() == false && getbusinessman() == false)
	{
		cout << name<<" aged "<<age<<" is not a student, not an employee and not a businessman." << endl;
	}
	total = t1 + t2 + t3;
	cout << "Total tax payable by person:" << total << endl;
}

void Person::setstudent(bool a)
{
	is_student = a;
}
bool Person::getstudent()
{
	return is_student;
}
void Person::setemployee(bool a)
{
	is_employee = a;
}
bool Person::getemployee()
{
	return is_employee;
}
void Person::setbusinessman(bool a)
{
	is_businessman = a;
}
bool Person::getbusinessman()
{
	return is_businessman;
}
double Person::gettax()
{
	return total;
}
void Person::setter()
{

}