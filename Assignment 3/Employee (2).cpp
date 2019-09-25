#include "pch.h"
#include "Employee.h"
#include <iostream>
#include "string"

Employee::Employee()
{
}

Employee::Employee(string a, string b, string c)
{
	setname(a);
	setssn(b);
	setemp_no(c);
}

Employee::~Employee()
{
}

void Employee::setname(string a)
{
	name=a;

}
string Employee::getname()
{
	return name;
}
void Employee::setssn(string a)
{
	ssn = correctssn(a);
}
string Employee::getssn()
{
	return ssn;
}
void Employee::setemp_no(string a)
{

	emp_no = correctemp_no(a);
}
string Employee::getemp_no()
{
	return emp_no;
}



string Employee::correctssn(string a)
{
	bool d = false;
		while (a.length() != 11)
		{
			cout << "Incorrect length entered for social security number. Enter numbers 0-9 with dashes in the format xxx-xx-xxxx (length 11). Enter again." << endl;
			cin >> a;
		}
		while (a[3] != '-' || a[6] != '-')
		{
			cout << "Your dashes are either misplaced or missing in the social security number. Remember to place them in the format xxx-xx-xxxx. Enter ssn again." << endl;
			cin >> a;
		}
		while (1)
		{
			d = false;
			for (int u = 0; u < a.length(); u++)
			{
				if (u != 3 && u != 6)
				{
					if (isdigit(a[u])==0)//is not a digit
					{
						d = true;
						break;
					}
				}
			}

			if (d == false)
			{
				break;
			}
			cout << "Remember to enter digits and dashes only in the social security number. Enter again." << endl;
			cin >> a;
		}
	return a;

}

string Employee::correctemp_no(string a)
{
	while (a.length() != 5)
	{
		cout << "Incorrect length entered for employee number. Enter numbers x within 0-9 with a dash and L being an alphabet from A-M in the format xxx-L (length 5). Enter again." << endl;
		cin >> a;
	}
	while (a[3] != '-')
	{
		cout << "Your dash is either misplaced or missing in the employee number. Remember to place them in the format xxx-L. Enter employee number again." << endl;
		cin >> a;
	}
	char c = a[4];

	int b = (int)c;
	
	while (b>77 || b<65)
	{
		cout << "Your last entered element needs to be an alphabet in upper case from A-M in the employee number. Enter again." << endl;
		cin >> a;
		c = a[4];
		b = (int)c;
		
	}
	while (1)
	{
		bool d = false;
		for (int u = 0; u < 3; u++)
		{
				if (isdigit(a[u]) == 0)//is not a digit
				{
					d = true;
					break;
				}
			
		}

		if (d == false)
		{
			break;
		}
		cout << "Remember to enter digits in the first three slots only. Enter again." << endl;
		cin >> a;
	}
	return a;
}