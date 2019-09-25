#pragma once
#include "EmployeePay.h"
class HourlyPay:public EmployeePay
{
private:
	double Hourly;
	double Overtime;
	int hours;
public:
	HourlyPay();
	~HourlyPay();
	HourlyPay(string a, string b, string c, double d, int e);
	void set(int a);
	int gethours();
	double getOvertime_pay_rate();
	double getHourly_pay_rate();
	int correcthours(int a);
};

