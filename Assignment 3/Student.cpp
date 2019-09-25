#include "pch.h"
#include "Student.h"
#include "Human.h"
#include "iostream"
#include <string>

Student::Student(string a, int b) :Human(a, b)
{
}

Student::Student()
{}


Student::~Student()
{
}

void Student::print()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Roll Number: " << getrollnum()<<endl;
	cout << "University Name: " << getuniname() << endl;
	//cout << "No of courses " << sizeof(courses)/sizeof(courses[0]) << endl;
	cout << "Courses: " << endl;
	for (int y = 0; y < c_no ;y++)
	{
		cout <<"Course "<<y+1<<": "<< *(getcourses() + y)<<endl;
	}
	cout << "Stipend: " << getstipend() << endl;
}

Student::Student(string a, int b, int c,  string d, string e[], int f, int g):Human(a ,b)
{
	setrollnum(c);
	setuniname(d);
	setstipend(f);
	c_no = g;
	string *temp= new std::string[c_no];
	for (int y = 0; y < g;y++)
	{
		*(temp + y) = e[y];
	}
	setcourses(temp, c_no);
	string qw = "1";
	string z = "";
	while (qw == "1")
	{
		cout << "Are you satisfied with the Student information entered? If not press 1 otherwise press 2." << endl;
		cin >> qw;
		while (qw != "1" && qw != "2")
		{
			cout << "Invalid entry. Try again." << endl;
			cin >> qw;
		}
		if (qw == "1")
		{
			cout << "What would you like to change? Press 1 for roll number, 2 for university name and 3 for stipend and 4 for courses." << endl;
			cin >> z;
			while (z != "1" && z != "2" && z != "3" && z != "4")
			{
				cout << "Invalid entry. Try again." << endl;
				cin >> g;
			}
			if (z == "1")
			{
				int x;
				cout << "Enter roll number" << endl;
				cin >> x;
				setrollnum(x);
			}
			else if (z == "2")
			{
				string x;
				cout << "Enter new university name" << endl;
				cin >> x;
				setuniname(x);
			}
			else if (z == "3")
			{
				int x;
				cout << "Enter new stipend" << endl;
				cin >> x;
				setstipend(x);
			}
			else
			{
				int x;
				cout << "Enter number of courses." << endl;
				cin >> x;
				string *lan = new std::string[x];
				cout << "Enter courses." << endl;
				for (int y = 0; y < x;y++)
				{
					cin >> *(lan + y);
				}
				setcourses(lan, x);

			}
		}
	}


}
int Student::getrollnum()
{
	return rollnum;
}
void Student::setrollnum(int a)
{
	rollnum = a;
}
string Student::getuniname()
{
	return uniname;
}
void Student::setuniname(string a)
{
	uniname = a;
}
string* Student::getcourses()
{
	return courses;
}
void Student::setcourses(string c[], int g)
{
	c_no = g;
	courses = new std::string[c_no];
	for (int y = 0; y < g;y++)
	{
		*(courses + y) = c[y];
	}
}
int Student::getstipend()
{
	return stipend;
}
void Student:: setstipend(int b){	stipend= b;}