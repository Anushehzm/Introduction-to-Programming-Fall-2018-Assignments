// EmployeeMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Employee.h"
#include "EmployeePay.h"
#include "HourlyPay.h"
#include "string"
using namespace std;


void PrintCheck(HourlyPay a)
{
	int h = a.gethours();
	double pr = a.getHourly_pay_rate();
	double o = a.getOvertime_pay_rate();
	cout << "Employee Name: " << a.getname() << "    Social Security Number: " << a.getssn() << "    Employee number: " << a.getemp_no() << endl;
	cout << "Hours worked: " << a.gethours() << endl;
	double total;
	if (h < 40)
	{
	
		total = h * pr;
	}
	else if (h>=40)
	{
		double overtime = (h - 40)*o;
		double hourly = 40 * pr;
		total = hourly + overtime;
	}
	cout << "Total hourly pay including potential overtime: " << total << endl;
	double w = (total * 40)/h;
	cout << "Yearly pay: " << w*52<<endl;
	cout << "Weekly pay: " << w<<endl;
}
int main()
{
	string a, b, c;
	double d;
	int e;

	cout << "Enter name of employee." << endl;
	cin >> a;
	cout << "Enter social security number of employee." << endl;
	cin >> b;
	cout << "Enter employee number of employee." << endl;
	cin >> c;
	cout << "Enter yearly pay employee." << endl;
	cin >> d;
	cout << "Enter hours worked by employee." << endl;
	cin >> e;
	HourlyPay person(a,b,c,d,e);
	PrintCheck(person);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
