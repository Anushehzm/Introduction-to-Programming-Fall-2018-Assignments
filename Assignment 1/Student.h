#pragma once
#include<string>
using namespace std;
class Student
{
private:
	int roll_number;
	int marks;
	string grade;
public:
	Student();
	~Student();
	void setter(int a, int b);
	void setter(string f);
	int get_rollno();
	int get_marks();
	string get_grade();
	friend void print(Student x);
};

