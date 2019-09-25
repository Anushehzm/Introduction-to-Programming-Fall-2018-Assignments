#include "pch.h"
#include "HourlyPay.h"
#include "iostream"

HourlyPay::HourlyPay()
{
}


HourlyPay::~HourlyPay()
{
}


HourlyPay::HourlyPay(string a, string b, string c, double d, int e):EmployeePay(a,b,c,d)
{
	set(e);
}

void HourlyPay::set(int a)
{
	hours = correcthours(a);
	Hourly = getweekly() / 40;
	Overtime = 1.5*Hourly;
}
int HourlyPay::gethours()
{
	return hours;
}
double HourlyPay::getOvertime_pay_rate()
{
	return Overtime;
}
double HourlyPay::getHourly_pay_rate()
{
	return Hourly;
}

int HourlyPay::correcthours(int a)
{
	while (a > 60 || a<0)
	{
		cout << "Hours worked cannot be greater than 60 or a negative number. Please enter again." << endl;
		cin >> a;
	}
	return a;
}