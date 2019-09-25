// Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Employee.h"
#include "Businessman.h"
#include "Person.h"
using namespace std;

/*void checker()
{

	qw = "1";
	z = "";
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
			while (z != "1" && z != "2" && z != "3" && z != "4")
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
			else if (z == "3")
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
					cin >> *(lan + y);
				}
				setlang(lan, x);

			}
		}
	}
}*/

template<typename A>

void Order(A *a, int e) 
{
	string b;
	cout << "If you want to arrange people in ascending order according to their tax payables, press 1 and if in descending order, press 2." << endl;
	cin >> b;
	while (b != "1" && b != "2")
	{
		cout << "Press either 1 or 2. Try again." << endl;
		cin >> b;
	}
	if (b == "1")//ascending
	{
		for (int w = 0; w < e-1; w++)
		{
			for (int q=0; q<e-w-1; q++)
			{
				if (a[q]->gettax() > a[q + 1]->gettax())
				{
					A n = a[q];
					a[q] = a[q + 1];
					a[q + 1] = n;
				}
			}
		}
	}
	else//descending
	{
		for (int w = 0; w < e - 1; w++)
		{
			for (int q = 0; q < e - w - 1; q++)
			{
				if (a[q]->gettax() < a[q + 1]->gettax())
				{
					A n = a[q];
					a[q] = a[q + 1];
					a[q + 1] = n;
				}
			}
		}
	}
}

int main()
{
	//student check
	/*string a, d;
	int w, b,  c, f;
	cout << "Enter name, age, roll number, uni name, and stipend" << endl;
	cin >> a >> b >> c >> d >> f;
	cout << "Enter number of courses." << endl;
	cin >> w;
	std::string *e = new std::string[w];
	cout<<"Enter courses: " << endl;
	for (int u = 0; u < w; u++)
	{
		cin >> e[u];
	}
	Student u(a, b, c, d, e,  f, w);
	cout << "Printing:" << endl;
	u.print();*/

	//employee check
	/*string a, d;
	int w, b, c, f;
	cout << "Enter name, age, emp ID, comp name, and salary" << endl;
	cin >> a >> b >> c >> d >> f;
	cout << "Enter number of languages." << endl;
	cin >> w;
	std::string *e = new std::string[w];
	cout << "Enter languages: " << endl;
	for (int u = 0; u < w; u++)
	{
		cin >> e[u];
	}
	Employee u(a, b, c, d, e, f, w);
	cout << "Printing:" << endl;
	u.print();*/

	//businessman
	/*string a, d;
	int b, c, f;
	cout << "Enter name, age, reg ID, comp name, and earning" << endl;
	cin >> a >> b >> c >> d >> f;
	Businessman u;
	cout << "Printing:" << endl;
	u.print();*/

	//person
	cout << "Enter number of people to enter their data." << endl;
	int p;
	cin >> p;
	while (p < 5)
	{
		cout << "Enter a value greater than 5." << endl;
		cin >> p;
	}
	Person *s[100];
	bool x, y, z;
	string a,q;
	int b;
	string  d;
	int g, c, f;
	string  i;
	int h, k, l;
	string n;
	std::string *j;
	std::string *e;
	int  m, o;
	for (int t=0; t<p; t++)
	{
		cout << "Enter name of person " <<t+1<<"."<< endl;
		cin >> a;
		cout << "Enter age of person " << t + 1 << "."<< endl;
		cin >> b;
		cout << "Is the person a student? Enter 1 for yes and 2 for no." << endl;
		cin >> q;
		while (q != "1" && q != "2")
		{
			cout << "Invalid entry. Enter again." << endl;
			cin >> q;
		}
		if (q == "1")
		{
			x = true;
			cout << "Enter roll number, university name, and stipend of student." << endl;
			cin >> c >> d >> f;
			cout << "Enter number of courses." << endl;
			cin >> g;
			e = new std::string[g];
			cout << "Enter courses: " << endl;
			for (int u = 0; u < g; u++)
			{
				cin >> e[u];
			}
		}
		else
		{
			x = false;
			c = 0;
			d = "";
			g = 0;
			f = 0;
			e = NULL;
		}
		cout << "Is the person an employee? Enter 1 for yes and 2 for no." << endl;
		cin >> q;
		while (q != "1" && q != "2")
		{
			cout << "Invalid entry. Enter again." << endl;
			cin >> q;
		}
		if (q == "1")
		{
			y = true;
			cout << "Enter employee ID, company name, and salary of employee" << endl;
			cin >> h >> i >> k;
			cout << "Enter number of languages." << endl;
			cin >> l;
			j = new std::string[l];
			cout << "Enter languages: " << endl;
			for (int u = 0; u < l; u++)
			{
				cin >> j[u];
			}
		}
		else
		{
			y = false;
			h = 0;
			i = "";
			j = NULL;
			k = 0;
			l = 0;

		}

		cout << "Is the person a businessman? Enter 1 for yes and 2 for no." << endl;
		cin >> q;
		while (q != "1" && q != "2")
		{
			cout << "Invalid entry. Enter again." << endl;
			cin >> q;
		}
		if (q == "1")
		{
			z = true;
			cout << "Enter registration ID, company name, and earning of businessman" << endl;
			cin >> m >> n >> o;
		}
		else
		{
			z = false;
			m = 0;
			n = "";
			o = 0;
		}
		s[t]=new Person(x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o);
	//	s[t].checker();
	
	}
	//Person r(x,y,z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);
	for (int we = 0; we < p; we++)
	{
		cout << "Information of person " << we + 1 << endl;
		s[we]->print();
		cout << endl;
	}
	
	Order(s,p);
	cout << "People arranged in order of tax payables: " << endl;
	
	for (int we = 0; we < p; we++)
	{
		cout << "Information of person " << we + 1 << endl;
		s[we]->print();
		cout << endl;
	}
	//r.print();
}
