#pragma once
#include "string"
using namespace std;
class Employee
{
private:
	string name;
	string ssn;
	string emp_no;
public:
	Employee();
	Employee(string a, string b, string c);
	~Employee();
	void setname(string a);
	string getname();
	void setssn(string a);
	string getssn();
	void setemp_no(string a);
	string getemp_no();
	string correctssn(string a);
	string correctemp_no(string a);

};

