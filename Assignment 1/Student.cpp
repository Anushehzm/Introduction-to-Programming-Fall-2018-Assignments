#include "pch.h"
#include "Student.h"
#include<iostream>
#include<string>
using namespace std;

Student::Student()
{
}


Student::~Student()
{
}

void Student::setter(int a, int b) //sets roll number and marks
{
	
	roll_number = a;
	marks = b;
}

void Student::setter(string f) //sets grade
{
		grade= f;
}

int Student::get_rollno()
{

	return roll_number;
}

int Student::get_marks()
{
	return marks;
}

string Student::get_grade()
{
	return grade;
}

void print(Student x)
{
	cout << "Student "<< x.get_rollno() << " has "<<  x.get_marks() << " marks and got "<< x.get_grade()<<" grade." << endl;
	//Student <roll number> has <marks> Marks and got <grade> Grade.
}