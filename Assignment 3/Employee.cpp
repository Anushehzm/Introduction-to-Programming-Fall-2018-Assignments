#include "pch.h"
#include "Employee.h"
#include "Human.h"
#include "iostream"
#include "string"
using namespace std;

Employee::Employee(string a, int b) :Human(a, b)
{
}

Employee::Employee()
{}

Employee::~Employee()
{
}

Employee::Employee(string a, int b, int c, string d, string e[], int f,int g):Human(a,b)
{
	setempID(c);
	setcompName(d);
	number=g;
	setsalary(f);
	string *temp = new std::string[number];
	for (int t = 0; t < number; t++)
	{
		*(temp + t) = e[t];
	}
	setlang(temp,number);
	string qw = "1";
	string z = "";
	while (qw == "1")
	{
		cout << "Are you satisfied with the Employee information entered? If not press 1 otherwise press 2." << endl;
		cin >> qw;
		while (qw != "1" && qw != "2")
		{
			cout << "Invalid entry. Try again." << endl;
			cin >> qw;
		}
		if (qw == "1")
		{
			cout << "What would you like to change? Press 1 for employee ID, 2 for company name and 3 for salary and 4 for languages." << endl;
			cin >> z;
			while (z != "1" && z != "2" && z != "3" && z!="4")
			{
				cout << "Invalid entry. Try again." << endl;
				cin >> g;
			}
			if (z == "1")
			{
				int x;
				cout << "Enter new employee ID" << endl;
				cin >> x;
				setempID(x);
			}
			else if (z == "2")
			{
				string x;
				cout << "Enter new company name" << endl;
				cin >> x;
				setcompName(x);
			}
			else if(z=="3")
			{
				int x;
				cout << "Enter new salary" << endl;
				cin >> x;
				setsalary(x);
			}
			else
			{
				int x;
				cout << "Enter number of languages." << endl;
				cin >> x;
				string *lan = new std::string[x];
				cout << "Enter languages." << endl;
				for (int y = 0; y < x;y++)
				{
					cin >> *(lan+y);
				}
				setlang(lan,x);

			}
		}
	}
}
void Employee::print()
{
	cout << "Name: " << getname() << endl;
	cout << "Age: " << getage() << endl;
	cout << "Employee ID: " << getempID() << endl;
	cout << "Company Name: " << getcompName() << endl;
	//cout << "No of courses " << sizeof(courses)/sizeof(courses[0]) << endl;
	cout << "Languages: " << endl;
	for (int y = 0; y < number;y++)
	{
		cout << "Language "<<y+1<<": "<<*(getlang() + y) << endl;
	}
	cout << "Salary: " << getsalary() << endl;


}
void Employee::setempID(int a)
{
	empID = a;
}
int Employee::getempID()
{
	return empID;
}
void Employee::setcompName(string a)
{
	compName = a;
}

string Employee::getcompName()
{
	return compName;
}

void Employee::setlang(string *a, int b)
{
	number = b;
	languages = new std::string[number];
	for (int e = 0; e < number; e++)
	{
		*(languages + e) = a[e];
	}
}
string * Employee::getlang()
{
	return languages;
}

void Employee::setsalary(int a)
{
	salary = a;
}
int Employee::getsalary()
{
	return salary;
}
