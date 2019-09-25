#include "pch.h"
#include "Businessman.h"
#include "Human.h"
#include "iostream"
#include "string"
using namespace std;

Businessman::Businessman(string a, int b) :Human(a, b)
{
}
Businessman::Businessman()
{}

Businessman::~Businessman()
{
}

Businessman::Businessman(string a, int b, int c, string d, int f) :Human(a, b)
{

	setregID(c);
	setcompName(d);
	setEarning(f);
	int first=0;
	string second="";
	int third=0;
	string qw = "1";
	string g = "";
	while (qw == "1")
	{
		cout << "Are you satisfied with the Businesman information entered? If not press 1 otherwise press 2." << endl;
		cin >> qw;
		while (qw != "1" && qw != "2")
		{
			cout << "Invalid entry. Try again." << endl;
			cin >> qw;
		}
		if (qw == "1")
		{
			cout << "What would you like to change? Press 1 for registration ID, 2 for company name and 3 for earning." << endl;
			cin >> g;
			while (g != "1" && g != "2" && g !="3")
			{
				cout << "Invalid entry. Try again." << endl;
				cin >> g;
			}
			if (g == "1")
			{
				cout << "Enter new registration ID" << endl;
				cin >> first;
				setregID(first);
			}
			else if (g == "2")
			{
				cout << "Enter new company name" << endl;
				cin >> second;
				setcompName(second);
			}
			else
			{
				cout << "Enter new earning" << endl;
				cin >> third;
				setEarning(third);
			}
		}
	}
}
void Businessman::print()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Registration ID: " << getregID() << endl;
	cout << "Company Name: " << getcompName() << endl;
	cout << "Earning: " << getEarning() << endl;
}
void Businessman::setregID(int a)
{
	regID = a;
}
int Businessman::getregID()
{
	return regID;
}
void Businessman::setcompName(string a)
{
	compName = a;
}

string Businessman::getcompName()
{
	return compName;
}

void Businessman::setEarning(int a)
{
	Earning = a;
}
int Businessman::getEarning()
{
	return Earning;
}
