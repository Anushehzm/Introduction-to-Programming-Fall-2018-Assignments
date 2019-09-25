#include "pch.h"
#include "Human.h"

Human::Human()
{}

Human::Human(string a, int b)
{
	setname(a);
	setage(b);
}


Human::~Human()
{
}

string Human::getname()
{
	return name;
}
void Human::setname(string d)
{
	name = d;
}
int Human::getage()
{
	return age;
}
void Human::setage(int r)
{
	age = r;
}