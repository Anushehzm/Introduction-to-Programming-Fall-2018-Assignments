#include "pch.h"
#include "EmployeePay.h"
#include "iostream"

EmployeePay::EmployeePay()
{
}


EmployeePay::~EmployeePay()
{
}

EmployeePay::EmployeePay(string a, string b, string c, double d):Employee(a,b,c)
{
	setpay(d);
}
void EmployeePay::setpay(double a)
{

	yearly_pay = correctpay(a);
	weekly_pay = (yearly_pay / 52.0);
}
double EmployeePay::getyearly()
{
	return yearly_pay;
}
/*void EmployeePay::setweekly(double a)
{
	weekly_pay = a;
}*/
double EmployeePay::getweekly()
{
	return weekly_pay;
}
double EmployeePay::correctpay(double a)
{
	while (a < 0)
	{
		cout << "The entered annual pay should not be negative. Enter again." << endl;
		cin >> a;
	}
	return a;
}