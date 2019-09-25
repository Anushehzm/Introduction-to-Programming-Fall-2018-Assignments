#include "pch.h"
#include "Array_Works_1.h"
#include <iostream>
#include <string>
using namespace std;
Array_Works_1::Array_Works_1(int size)
{
	size_1 = size;
	count_add = 0;
	Array = new char[size];
	
	
}


Array_Works_1::~Array_Works_1()
{
}

char Array_Works_1:: Add_element(char c)
{
	if (count_add == size_1)
	{
		cout << "Your array is full. Can't add more elements to it. " << endl;
	}
	else
	{
		Array[count_add] = c;
		count_add++;
	}
	cout << "Now your array is:" << endl;
	for (int u = 0; u < count_add; u++)
	{
		cout << Array[u];
	}
	cout << endl;
	return c;
}
char Array_Works_1::delete_element()
{
	char r;
	if (count_add == 0)
	{
		cout << "Array is empty. You can't delete or peak at any elements." << endl;
		r= ' ';
		return r;
	}
	else
	{
		r = Array[count_add-1];
		cout << "Topmost character: '"<<r<<"'"<<endl;
		Array[count_add-1] = ' ';
		count_add--;

	}

	/*if (count_add == 0)
	{
		cout << "Your array is now empty" << endl;
	}
	else
	{
		cout << "Now your remaining array is:" << endl;
		for (int u = 0; u < count_add; u++)
		{
			cout << Array[u];
		}
		cout << endl;
	}*/
	return r;
}

void Array_Works_1::peek()
{
	Add_element(delete_element());
}

int Array_Works_1::size()
{
	return count_add;
}
bool Array_Works_1::is_empty()
{
	if (count_add == 0)
	{
		return true;
	}
	else
		return false;
}
bool Array_Works_1::is_full()
{
	if (count_add == size_1)
	{
		return true;
	}
	else
		return false;
}