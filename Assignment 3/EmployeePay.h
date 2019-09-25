#pragma once
#include "Employee.h"
class EmployeePay: public Employee
{
private:
	double yearly_pay;
	double weekly_pay;
public:
	EmployeePay();
	~EmployeePay();
	EmployeePay(string a, string b, string c,double d);
	void setpay(double a);
	double getyearly();
	//void setweekly(double a);
	double getweekly();
	double correctpay(double a);
};

